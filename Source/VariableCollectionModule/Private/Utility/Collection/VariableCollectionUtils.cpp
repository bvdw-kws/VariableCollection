// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

#include "VariableCollectionUtils.h"

#include "Collection/VariableCollection.h"
#include "Engine/AssetManager.h"

namespace VariableCollection::Utils
{
	
#if WITH_EDITOR
static bool IsAssetDataBlueprintOfClassSet(const FAssetData& AssetData, const TSet<FTopLevelAssetPath>& ClassNameSet)
{
	const FString ParentClassFromData = AssetData.GetTagValueRef<FString>(FBlueprintTags::ParentClassPath);
	if (!ParentClassFromData.IsEmpty())
	{
		const FTopLevelAssetPath ClassObjectPath(FPackageName::ExportTextPathToObjectPath(ParentClassFromData));
		const FName ClassName = ClassObjectPath.GetAssetName();

		TArray<FTopLevelAssetPath> ValidNames;
		ValidNames.Add(ClassObjectPath);
		// Check for redirected name
		FTopLevelAssetPath RedirectedName = FTopLevelAssetPath(FLinkerLoad::FindNewPathNameForClass(ClassObjectPath.ToString(), false));
		if (!RedirectedName.IsNull())
		{
			ValidNames.Add(RedirectedName);
		}
		for (const FTopLevelAssetPath& ValidName : ValidNames)
		{
			if (ClassNameSet.Contains(ValidName))
			{
				// Our parent class is in the class name set
				return true;
			}
		}
	}
	return false;
}

static void GetBlueprintAssets(const FARFilter& InFilter, TArray<FAssetData>& OutAssetData)
{
	IAssetRegistry& AssetRegistry = IAssetRegistry::GetChecked();

	FARFilter Filter(InFilter);
	PRAGMA_DISABLE_DEPRECATION_WARNINGS;
	UE_CLOG(!InFilter.ClassNames.IsEmpty(), LogCore, Error,
		TEXT("ARFilter.ClassNames is not supported by UAssetRegistryHelpers::GetBlueprintAssets and will be ignored."));
	Filter.ClassNames.Empty();
	PRAGMA_ENABLE_DEPRECATION_WARNINGS;

	// Expand list of classes to include derived classes
	TArray<FTopLevelAssetPath> BlueprintParentClassPathRoots = MoveTemp(Filter.ClassPaths);
	TSet<FTopLevelAssetPath> BlueprintParentClassPaths;
	if (Filter.bRecursiveClasses)
	{
		AssetRegistry.GetDerivedClassNames(
			BlueprintParentClassPathRoots, 
			TSet<FTopLevelAssetPath>(),
			 BlueprintParentClassPaths
			 );
	}
	else
	{
		BlueprintParentClassPaths.Append(BlueprintParentClassPathRoots);
	}

	// Search for all blueprints and then check BlueprintParentClassPaths in the results
	Filter.ClassPaths.Reset(1);
	Filter.ClassPaths.Add(FTopLevelAssetPath(FName(TEXT("/Script/Engine")), FName(TEXT("BlueprintCore"))));
	Filter.bRecursiveClasses = true;

	auto FilterLambda = [&OutAssetData, &BlueprintParentClassPaths](const FAssetData& AssetData)
	{
		// Verify blueprint class
		if (BlueprintParentClassPaths.IsEmpty() || IsAssetDataBlueprintOfClassSet(AssetData, BlueprintParentClassPaths))
		{
			OutAssetData.Add(AssetData);
		}
		return true;
	};
	AssetRegistry.EnumerateAssets(Filter, FilterLambda, UE::AssetRegistry::EEnumerateAssetsFlags::None);
}
#endif // WITH_EDITOR
	
static TArray<UVariableCollection*> GetVariableCollectionAssets()
{
	TArray<FAssetData> AllCollections;
	UAssetManager::Get().GetPrimaryAssetDataList(FPrimaryAssetType(TEXT("VariableCollectionData")), AllCollections);

	TArray<UVariableCollection*> Results;
	Results.Reserve(AllCollections.Num());

	for (const FAssetData& AssetData : AllCollections)
	{
		const FString AssetPath = AssetData.GetObjectPathString();
		if (UVariableCollection* Asset = LoadObject<UVariableCollection>(NULL, *AssetPath))
		{
			Results.Add(Asset);
		}
	}

	return Results;
}
	
static TArray<UClass*> GetVariableCollectionClasses()
{
	TArray<FAssetData> BlueprintAssets;
#if WITH_EDITOR	
	FARFilter Filter;
	Filter.ClassPaths.Add(UVariableCollection::StaticClass()->GetClassPathName());
	Filter.bRecursiveClasses = true;
	Filter.bRecursivePaths = true;
	
	GetBlueprintAssets(Filter, BlueprintAssets);
#else // WITH_EDITOR	
	FARFilter Filter;
	Filter.ClassPaths.Add(UBlueprint::StaticClass()->GetClassPathName());
	Filter.bRecursiveClasses = true;
	Filter.bRecursivePaths = true;
	Filter.bIncludeOnlyOnDiskAssets = true;
	Filter.TagsAndValues.Add(FBlueprintTags::NativeParentClassPath, FObjectPropertyBase::GetExportPath(UVariableCollection::StaticClass()));
	Filter.TagsAndValues.Add(FBlueprintTags::ParentClassPath, FObjectPropertyBase::GetExportPath(UVariableCollection::StaticClass()));
	
	const FAssetRegistryModule& AssetRegistryModule = FModuleManager::LoadModuleChecked<FAssetRegistryModule>(TEXT("AssetRegistry"));
	AssetRegistryModule.Get().GetAssets(Filter, BlueprintAssets);
#endif

	TArray<UClass*> Results;
	
	for (const FAssetData& AssetData : BlueprintAssets)
	{
		const FString AssetPath = FString::Printf(TEXT("Blueprint'%s_C'"), *AssetData.GetObjectPathString());
		if (UClass* AssetClass = LoadObject<UClass>(NULL, *AssetPath))
		{
			Results.Add(AssetClass);
		}
	}

	return Results;
}
	
TArray<FName> GetPropertyNames(const TFunction<bool(const FProperty*)>& PropertyEvaluatorFunc)
{
	TArray<FName> PropertyNames;
	PropertyNames.Add(NAME_None);

#if WITH_EDITOR
	for (const UVariableCollection* VariableCollectionAsset : GetVariableCollectionAssets())
	{
		const FString CollectionName = VariableCollectionAsset->GetName();
		
		for (TFieldIterator<FProperty> It(VariableCollectionAsset->GetClass()); It; ++It)
		{
			const FProperty* ObjProperty = *It;
			if (!PropertyEvaluatorFunc(ObjProperty))
			{
				continue;
			}

			const FString PropertyName = ObjProperty->GetFName().ToString();
			PropertyNames.Add(*FString::Printf(TEXT("%s.%s"), *CollectionName, *PropertyName));
		}
	}
#endif // WITH_EDITOR

	return PropertyNames;
}

bool GetVariableCollectionProperty(const FName& Binding,
	TObjectPtr<UObject>& OutOwnerCollection, TFieldPath<FProperty>& OutProperty,
	const TFunction<bool(const FProperty*)>& PropertyEvaluatorFunc)
{
	if (Binding.IsNone())
	{
		OutOwnerCollection = nullptr;
		OutProperty = nullptr;
		return false;
	}
	
	FString CollectionName;
	FString PropertyName;
	Binding.ToString().Split(".", &CollectionName, &PropertyName);

	if (OutOwnerCollection && OutOwnerCollection->GetName() == CollectionName &&
		OutProperty != nullptr && OutProperty->GetFName() == PropertyName)
	{
		return true;
	}

	FAssetData AssetData;
	if (UAssetManager::Get().GetPrimaryAssetData(
			FPrimaryAssetId(TEXT("VariableCollectionData"), *CollectionName), AssetData))
	{
		UVariableCollection* VariableCollectionAsset = LoadObject<UVariableCollection>(
			NULL, *AssetData.GetObjectPathString());
		if (!IsValid(VariableCollectionAsset))
		{
			return false;
		}
		
		for (TFieldIterator<FProperty> It(VariableCollectionAsset->GetClass()); It; ++It)
		{
			FProperty* ObjProperty = *It;
			if (ObjProperty->GetFName() != PropertyName || !PropertyEvaluatorFunc(ObjProperty))
			{
				continue;
			}
					
			OutOwnerCollection = VariableCollectionAsset;
			OutProperty = ObjProperty;
			return true;
		}
	}

	return false;
}

FString GetCollectionClassName_DEPRECATED(const UClass* Class)
{
	if (Class)
	{
		FString CollectionName = Class->GetName();
		CollectionName.RemoveFromEnd(TEXT("_C"));
		return CollectionName;
	}
	return FString();
}
	
} // namespace VariableCollection::Utils
