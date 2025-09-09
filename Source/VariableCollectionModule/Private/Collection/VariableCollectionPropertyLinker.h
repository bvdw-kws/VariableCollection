// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "CoreMinimal.h"

#include "VariableCollectionPropertyLinker.generated.h"

UCLASS(Abstract, DefaultToInstanced, EditInlineNew)
class UVariableCollectionPropertyLinker : public UObject
{
	GENERATED_BODY()

public:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const { return false; }
	
#if WITH_EDITOR
public:
	virtual void PostEditChangeProperty(struct FPropertyChangedEvent& PropertyChangedEvent) override;
#endif // WITH_EDITOR

public:
	virtual void PostLoad() override;
	virtual void PostDuplicate(bool bDuplicateForPIE) override;

public:
	void SetFromVariableBinding(const FName& Binding);
	
protected:
	UPROPERTY(meta=(DeprecatedProperty))
	TSubclassOf<UObject> OwnerCollection_DEPRECATED;
	UPROPERTY()
	TObjectPtr<UObject> OwnerCollectionAsset;
	UPROPERTY()
	TFieldPath<FProperty> Property;

#if WITH_EDITORONLY_DATA
protected:
	UPROPERTY(EditAnywhere, Transient, meta=(GetOptions="GetPropertyNames"), DisplayName="Value")
	FName Variable = NAME_None;
#endif // WITH_EDITORONLY_DATA

private:
	UFUNCTION()
	TArray<FName> GetPropertyNames() const;
	
#if WITH_EDITOR
private:
	void ApplyProperty();
#endif // WITH_EDITOR
};

UCLASS(DisplayName="Float")
class UVariableCollectionFloatPropertyLinker : public UVariableCollectionPropertyLinker
{
	GENERATED_BODY()

public:
	float GetVariableValue(float DefaultValue) const;

protected:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const override;
};

UCLASS(DisplayName="Bool")
class UVariableCollectionBoolPropertyLinker : public UVariableCollectionPropertyLinker
{
	GENERATED_BODY()

public:
	bool GetVariableValue(bool DefaultValue) const;

protected:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const override;
};

UCLASS(DisplayName="Int")
class UVariableCollectionIntPropertyLinker : public UVariableCollectionPropertyLinker
{
	GENERATED_BODY()

public:
	int32 GetVariableValue(int32 DefaultValue) const;

protected:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const override;
};

UCLASS(DisplayName="Vector")
class UVariableCollectionVectorPropertyLinker : public UVariableCollectionPropertyLinker
{
	GENERATED_BODY()

public:
	FVector GetVariableValue(const FVector& DefaultValue) const;

protected:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const override;
};

UCLASS(DisplayName="Rotator")
class UVariableCollectionRotatorPropertyLinker : public UVariableCollectionPropertyLinker
{
	GENERATED_BODY()

public:
	FRotator GetVariableValue(const FRotator& DefaultValue) const;

protected:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const override;
};

UCLASS(DisplayName="Curve Float")
class UVariableCollectionCurveFloatPropertyLinker : public UVariableCollectionPropertyLinker
{
	GENERATED_BODY()

public:
	TObjectPtr<UCurveFloat> GetVariableValue(const TObjectPtr<UCurveFloat>& DefaultValue) const;

protected:
	virtual bool IsValidPropertyType(const FProperty* ObjProperty) const override;
};
