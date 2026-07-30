// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0


#include "VariableCollectionPropertyLinker.h"

#include "Collection/VariableCollection.h"
#include "Utility/Collection/VariableCollectionUtils.h"

//----------------------------------------------------------------------//
// UVariableCollectionPropertyLinker
//----------------------------------------------------------------------//
void UVariableCollectionPropertyLinker::PostLoad()
{
	Super::PostLoad();
	
#if WITH_EDITOR
	if (OwnerCollectionAsset && Property != nullptr)
	{
		Variable = *FString::Printf(TEXT("%s.%s"),
			*OwnerCollectionAsset->GetName(), *Property->GetFName().ToString());
	}
	else if (OwnerCollection_DEPRECATED && Property != nullptr)
	{
		Variable = *FString::Printf(TEXT("%s.%s"),
			*VariableCollection::Utils::GetCollectionClassName_DEPRECATED(
				OwnerCollection_DEPRECATED), *Property->GetFName().ToString());
		Variable = *Variable.ToString().Replace(TEXT("BP_"), TEXT("DA_"));

		SetFromVariableBinding(Variable);
		if (OwnerCollectionAsset && Property != nullptr)
		{
			OwnerCollection_DEPRECATED = nullptr;
			Modify();
		}
	}
#endif // WITH_EDITOR
}

void UVariableCollectionPropertyLinker::PostDuplicate(bool bDuplicateForPIE)
{
	UObject::PostDuplicate(bDuplicateForPIE);
	
#if WITH_EDITOR
	if (!bDuplicateForPIE && OwnerCollectionAsset && Property != nullptr)
	{
		Variable = *FString::Printf(TEXT("%s.%s"),
			*OwnerCollectionAsset->GetName(), *Property->GetFName().ToString());
	}
#endif // WITH_EDITOR
}

#if WITH_EDITOR
void UVariableCollectionPropertyLinker::PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent)
{
	Super::PostEditChangeProperty(PropertyChangedEvent);

	if (PropertyChangedEvent.GetPropertyName() == TEXT("Variable"))
	{
		ApplyProperty();
	}
}

void UVariableCollectionPropertyLinker::ApplyProperty()
{
#if WITH_EDITORONLY_DATA
	SetFromVariableBinding(Variable);
#endif // WITH_EDITORONLY_DATA
}
#endif // WITH_EDITOR

TArray<FName> UVariableCollectionPropertyLinker::GetPropertyNames() const
{
	return VariableCollection::Utils::GetPropertyNames([this](const FProperty* InProperty)
	{
		return IsValidPropertyType(InProperty);
	});
}

void UVariableCollectionPropertyLinker::SetFromVariableBinding(const FName& Binding)
{
	VariableCollection::Utils::GetVariableCollectionProperty(Binding, OwnerCollectionAsset, Property,
		[this](const FProperty* InProperty)
	{
		return IsValidPropertyType(InProperty);
	});
}

//----------------------------------------------------------------------//
// UVariableCollectionFloatPropertyLinker
//----------------------------------------------------------------------//
float UVariableCollectionFloatPropertyLinker::GetVariableValue(float DefaultValue) const
{
	if (OwnerCollectionAsset)
	{
		if (const FNumericProperty* FloatProperty = CastField<FNumericProperty>(Property.Get()))
		{
			const void* ValuePtr = FloatProperty->template ContainerPtrToValuePtr<void>(OwnerCollectionAsset);
			return FloatProperty->GetFloatingPointPropertyValue(ValuePtr);
		}
	}
	return DefaultValue;
}

bool UVariableCollectionFloatPropertyLinker::IsValidPropertyType(const FProperty* ObjProperty) const
{
	if (const FNumericProperty* FloatProperty = CastField<FNumericProperty>(ObjProperty))
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------//
// UVariableCollectionBoolPropertyLinker
//----------------------------------------------------------------------//
bool UVariableCollectionBoolPropertyLinker::GetVariableValue(bool DefaultValue) const
{
	if (OwnerCollectionAsset)
	{
		if (const FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property.Get()))
		{
			const void* ValuePtr = BoolProperty->template ContainerPtrToValuePtr<void>(OwnerCollectionAsset);
			return BoolProperty->GetPropertyValue(ValuePtr);
		}
	}
	return DefaultValue;
}

bool UVariableCollectionBoolPropertyLinker::IsValidPropertyType(const FProperty* ObjProperty) const
{
	if (const FBoolProperty* BoolProperty = CastField<FBoolProperty>(ObjProperty))
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------//
// UVariableCollectionIntPropertyLinker
//----------------------------------------------------------------------//
int32 UVariableCollectionIntPropertyLinker::GetVariableValue(int32 DefaultValue) const
{
	if (OwnerCollectionAsset)
	{
		if (const FNumericProperty* IntProperty = CastField<FNumericProperty>(Property.Get()))
		{
			const void* ValuePtr = IntProperty->template ContainerPtrToValuePtr<void>(OwnerCollectionAsset);
			return IntProperty->GetSignedIntPropertyValue(ValuePtr);
		}
	}
	return DefaultValue;
}

bool UVariableCollectionIntPropertyLinker::IsValidPropertyType(const FProperty* ObjProperty) const
{
	if (const FNumericProperty* IntProperty = CastField<FNumericProperty>(ObjProperty))
	{
		return true;
	}
	return false;
}

//----------------------------------------------------------------------//
// UVariableCollectionVectorPropertyLinker
//----------------------------------------------------------------------//
FVector UVariableCollectionVectorPropertyLinker::GetVariableValue(const FVector& DefaultValue) const
{
	if (OwnerCollectionAsset)
	{
		if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property.Get()))
		{		
			if (StructProperty->Struct == TBaseStructure<FVector>::Get())
			{
				const void* ValueAddress = Property->ContainerPtrToValuePtr<void>(OwnerCollectionAsset);
				return *static_cast<FVector const*>(ValueAddress);
			}			
		}
	}
	return DefaultValue;
}

bool UVariableCollectionVectorPropertyLinker::IsValidPropertyType(const FProperty* ObjProperty) const
{
	if (const FStructProperty* StructProperty = CastField<FStructProperty>(ObjProperty))
	{
		return StructProperty->Struct == TBaseStructure<FVector>::Get();
	}
	return false;
}

//----------------------------------------------------------------------//
// UVariableCollectionRotatorPropertyLinker
//----------------------------------------------------------------------//
FRotator UVariableCollectionRotatorPropertyLinker::GetVariableValue(const FRotator& DefaultValue) const
{
	if (OwnerCollectionAsset)
	{
		if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property.Get()))
		{		
			if (StructProperty->Struct == TBaseStructure<FRotator>::Get())
			{
				const void* ValueAddress = Property->ContainerPtrToValuePtr<void>(OwnerCollectionAsset);
				return *static_cast<FRotator const*>(ValueAddress);
			}			
		}
	}
	return DefaultValue;
}

bool UVariableCollectionRotatorPropertyLinker::IsValidPropertyType(const FProperty* ObjProperty) const
{
	if (const FStructProperty* StructProperty = CastField<FStructProperty>(ObjProperty))
	{
		return StructProperty->Struct == TBaseStructure<FRotator>::Get();
	}
	return false;
}

//----------------------------------------------------------------------//
// UVariableCollectionCurveFloatPropertyLinker
//----------------------------------------------------------------------//
TObjectPtr<UCurveFloat> UVariableCollectionCurveFloatPropertyLinker::GetVariableValue(const TObjectPtr<UCurveFloat>& DefaultValue) const
{
	if (OwnerCollectionAsset)
	{
		if (const FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(Property.Get()))
		{
			if (ObjProp->PropertyClass == UCurveFloat::StaticClass())
			{
				const uint8* ValuePtr = ObjProp->ContainerPtrToValuePtr<uint8>(OwnerCollectionAsset);
				return Cast<UCurveFloat>(ObjProp->GetObjectPropertyValue(ValuePtr));
			}
		}
	}
	return DefaultValue;
}

bool UVariableCollectionCurveFloatPropertyLinker::IsValidPropertyType(const FProperty* ObjProperty) const
{
	if (const FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(ObjProperty))
	{
		return ObjProp && ObjProp->PropertyClass == UCurveFloat::StaticClass();
	}
	return false;
}
