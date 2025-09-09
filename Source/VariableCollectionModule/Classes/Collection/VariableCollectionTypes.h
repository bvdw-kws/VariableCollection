// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "CoreMinimal.h"

#include "VariableCollectionTypes.generated.h"

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/VariableCollectionModule.VariableCollectionFunctionLibrary.MakeVariableCollection_Float"))
struct VARIABLECOLLECTIONMODULE_API FVariableCollectionFloat
{
	GENERATED_BODY()

public:
	FVariableCollectionFloat(float InDefaultValue = 0.0f);

	float GetValue() const;
	operator float() const { return GetValue(); }

	void SetFromVariableBinding(FName Binding);
	
protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, meta=(ShowInnerProperties), DisplayName="Binding")
	TObjectPtr<class UVariableCollectionFloatPropertyLinker> Value;

	UPROPERTY(EditAnywhere)
	float DefaultValue = 0.0f;
};

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/VariableCollectionModule.VariableCollectionFunctionLibrary.MakeVariableCollection_Bool"))
struct VARIABLECOLLECTIONMODULE_API FVariableCollectionBool
{
	GENERATED_BODY()

public:
	FVariableCollectionBool(bool InDefaultValue = false);

	bool GetValue() const;
	operator bool() const { return GetValue(); }

	void SetFromVariableBinding(FName Binding);
	
protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, meta=(ShowInnerProperties), DisplayName="Binding")
	TObjectPtr<class UVariableCollectionBoolPropertyLinker> Value;

	UPROPERTY(EditAnywhere)
	bool DefaultValue = false;
};

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/VariableCollectionModule.VariableCollectionFunctionLibrary.MakeVariableCollection_Int"))
struct VARIABLECOLLECTIONMODULE_API FVariableCollectionInt
{
	GENERATED_BODY()

public:
	FVariableCollectionInt(int32 InDefaultValue = 0);

	int32 GetValue() const;
	operator int32() const { return GetValue(); }

	void SetFromVariableBinding(FName Binding);
	
protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, meta=(ShowInnerProperties), DisplayName="Binding")
	TObjectPtr<class UVariableCollectionIntPropertyLinker> Value;

	UPROPERTY(EditAnywhere)
	int32 DefaultValue = 0;
};

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/VariableCollectionModule.VariableCollectionFunctionLibrary.MakeVariableCollection_Vector"))
struct VARIABLECOLLECTIONMODULE_API FVariableCollectionVector
{
	GENERATED_BODY()

public:
	FVariableCollectionVector(FVector InDefaultValue = FVector::ZeroVector);

	FVector GetValue() const;
	operator FVector() const { return GetValue(); }

	void SetFromVariableBinding(FName Binding);
	
protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, meta=(ShowInnerProperties), DisplayName="Binding")
	TObjectPtr<class UVariableCollectionVectorPropertyLinker> Value;

	UPROPERTY(EditAnywhere)
	FVector DefaultValue = FVector::ZeroVector;
};

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/VariableCollectionModule.VariableCollectionFunctionLibrary.MakeVariableCollection_Rotator"))
struct VARIABLECOLLECTIONMODULE_API FVariableCollectionRotator
{
	GENERATED_BODY()

public:
	FVariableCollectionRotator(FRotator InDefaultValue = FRotator::ZeroRotator);

	FRotator GetValue() const;
	operator FRotator() const { return GetValue(); }

	void SetFromVariableBinding(FName Binding);
	
protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, meta=(ShowInnerProperties), DisplayName="Binding")
	TObjectPtr<class UVariableCollectionRotatorPropertyLinker> Value;

	UPROPERTY(EditAnywhere)
	FRotator DefaultValue = FRotator::ZeroRotator;
};

USTRUCT(BlueprintType, meta=(HasNativeMake="/Script/VariableCollectionModule.VariableCollectionFunctionLibrary.MakeVariableCollection_CurveFloat"))
struct VARIABLECOLLECTIONMODULE_API FVariableCollectionCurveFloat
{
	GENERATED_BODY()

public:
	FVariableCollectionCurveFloat(TObjectPtr<UCurveFloat> InDefaultValue = TObjectPtr<UCurveFloat>());

	TObjectPtr<UCurveFloat> GetValue() const;
	operator TObjectPtr<UCurveFloat>() const { return GetValue(); }
	bool IsSet() const { return GetValue() != nullptr; }

	void SetFromVariableBinding(FName Binding);
	
protected:
	UPROPERTY(EditAnywhere, NoClear, Instanced, meta=(ShowInnerProperties), DisplayName="Binding")
	TObjectPtr<class UVariableCollectionCurveFloatPropertyLinker> Value;

	UPROPERTY(EditAnywhere)
	TObjectPtr<UCurveFloat> DefaultValue;
};
