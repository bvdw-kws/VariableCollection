// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "Kismet/BlueprintFunctionLibrary.h"
#include "Collection/VariableCollectionTypes.h"

#include "VariableCollectionFunctionLibrary.generated.h"

UCLASS()
class VARIABLECOLLECTIONMODULE_API UVariableCollectionFunctionLibrary : public UBlueprintFunctionLibrary
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category="Variable Collection")
	static float GetVariableCollectionFloatValue(const FVariableCollectionFloat& Variable);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection")
	static bool GetVariableCollectionBoolValue(const FVariableCollectionBool& Variable);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection")
	static int32 GetVariableCollectionIntValue(const FVariableCollectionInt& Variable);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection")
	static FVector GetVariableCollectionVectorValue(const FVariableCollectionVector& Variable);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection")
	static FRotator GetVariableCollectionRotatorValue(const FVariableCollectionRotator& Variable);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection")
	static UCurveFloat* GetVariableCollectionCurveFloatValue(const FVariableCollectionCurveFloat& Variable);

	UFUNCTION(BlueprintPure, Category="Variable Collection", meta=(NativeMakeFunc))
	static FVariableCollectionFloat MakeVariableCollection_Float(
		UPARAM(Meta=(GetOptions="GetFloatPropertyNames")) const FName Binding,
		float DefaultValue = 0.0f);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection", meta=(NativeMakeFunc))
	static FVariableCollectionInt MakeVariableCollection_Int(
	UPARAM(Meta=(GetOptions="GetIntPropertyNames")) const FName Binding,
		int32 DefaultValue = 0);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection", meta=(NativeMakeFunc))
	static FVariableCollectionBool MakeVariableCollection_Bool(
		UPARAM(Meta=(GetOptions="GetBoolPropertyNames")) const FName Binding,
		bool DefaultValue = false);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection", meta=(NativeMakeFunc))
	static FVariableCollectionVector MakeVariableCollection_Vector(
		UPARAM(Meta=(GetOptions="GetVectorPropertyNames")) const FName Binding,
		FVector DefaultValue = FVector::ZeroVector);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection", meta=(NativeMakeFunc))
	static FVariableCollectionRotator MakeVariableCollection_Rotator(
		UPARAM(Meta=(GetOptions="GetRotatorPropertyNames")) const FName Binding,
		FRotator DefaultValue = FRotator::ZeroRotator);
	
	UFUNCTION(BlueprintPure, Category="Variable Collection", meta=(NativeMakeFunc))
	static FVariableCollectionCurveFloat MakeVariableCollection_CurveFloat(
		UPARAM(Meta=(GetOptions="GetCurveFloatPropertyNames")) const FName Binding,
		UCurveFloat* DefaultValue = nullptr);

protected:
	UFUNCTION()
	static TArray<FName> GetFloatPropertyNames();
	UFUNCTION()
	static TArray<FName> GetIntPropertyNames();
	UFUNCTION()
	static TArray<FName> GetBoolPropertyNames();
	UFUNCTION()
	static TArray<FName> GetVectorPropertyNames();
	UFUNCTION()
	static TArray<FName> GetRotatorPropertyNames();
	UFUNCTION()
	static TArray<FName> GetCurveFloatPropertyNames();
};
