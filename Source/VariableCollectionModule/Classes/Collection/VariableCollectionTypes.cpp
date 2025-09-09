// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0


#include "VariableCollectionTypes.h"

#include "Collection/VariableCollectionPropertyLinker.h"

template<typename T>
static void SetFromVariableBinding(TObjectPtr<T>& Value, FName Binding)
{
	Value = NewObject<T>();
	if (Value)
	{
		Value->SetFromVariableBinding(Binding);
	}
}

//----------------------------------------------------------------------//
// FVariableFloatProperty
//----------------------------------------------------------------------//
FVariableCollectionFloat::FVariableCollectionFloat(float InDefaultValue)
	: DefaultValue(InDefaultValue)
{
}

float FVariableCollectionFloat::GetValue() const
{
	if (Value)
	{
		return Value->GetVariableValue(DefaultValue);
	}
	return DefaultValue;
}

void FVariableCollectionFloat::SetFromVariableBinding(FName Binding)
{
	::SetFromVariableBinding<UVariableCollectionFloatPropertyLinker>(Value, Binding);
}

//----------------------------------------------------------------------//
// FVariableBoolProperty
//----------------------------------------------------------------------//
FVariableCollectionBool::FVariableCollectionBool(bool InDefaultValue)
	: DefaultValue(InDefaultValue)
{
}

bool FVariableCollectionBool::GetValue() const
{
	if (Value)
	{
		return Value->GetVariableValue(DefaultValue);
	}
	return DefaultValue;
}

void FVariableCollectionBool::SetFromVariableBinding(FName Binding)
{
	::SetFromVariableBinding<UVariableCollectionBoolPropertyLinker>(Value, Binding);
}

//----------------------------------------------------------------------//
// FVariableIntProperty
//----------------------------------------------------------------------//
FVariableCollectionInt::FVariableCollectionInt(int32 InDefaultValue)
	: DefaultValue(InDefaultValue)
{
}

int32 FVariableCollectionInt::GetValue() const
{
	if (Value)
	{
		return Value->GetVariableValue(DefaultValue);
	}
	return DefaultValue;
}

void FVariableCollectionInt::SetFromVariableBinding(FName Binding)
{
	::SetFromVariableBinding<UVariableCollectionIntPropertyLinker>(Value, Binding);
}

//----------------------------------------------------------------------//
// FVariableVectorProperty
//----------------------------------------------------------------------//
FVariableCollectionVector::FVariableCollectionVector(FVector InDefaultValue /*= FVector::ZeroVector*/)
	: DefaultValue(InDefaultValue)
{
}

FVector FVariableCollectionVector::GetValue() const
{
	if (Value)
	{
		return Value->GetVariableValue(DefaultValue);
	}
	return DefaultValue;
}

void FVariableCollectionVector::SetFromVariableBinding(FName Binding)
{
	::SetFromVariableBinding<UVariableCollectionVectorPropertyLinker>(Value, Binding);
}

//----------------------------------------------------------------------//
// FVariableRotatorProperty
//----------------------------------------------------------------------//
FVariableCollectionRotator::FVariableCollectionRotator(FRotator InDefaultValue /*= FRotator::ZeroRotator*/)
	: DefaultValue(InDefaultValue)
{
}

FRotator FVariableCollectionRotator::GetValue() const
{
	if (Value)
	{
		return Value->GetVariableValue(DefaultValue);
	}
	return DefaultValue;
}

void FVariableCollectionRotator::SetFromVariableBinding(FName Binding)
{
	::SetFromVariableBinding<UVariableCollectionRotatorPropertyLinker>(Value, Binding);
}

//----------------------------------------------------------------------//
// FVariableCurveFloatProperty
//----------------------------------------------------------------------//
FVariableCollectionCurveFloat::FVariableCollectionCurveFloat(TObjectPtr<UCurveFloat> InDefaultValue /*= TObjectPtr<UCurveFloat>::ZeroCurveFloat*/)
	: DefaultValue(InDefaultValue)
{
}

TObjectPtr<UCurveFloat> FVariableCollectionCurveFloat::GetValue() const
{
	if (Value)
	{
		return Value->GetVariableValue(DefaultValue);
	}
	return DefaultValue;
}

void FVariableCollectionCurveFloat::SetFromVariableBinding(FName Binding)
{
	::SetFromVariableBinding<UVariableCollectionCurveFloatPropertyLinker>(Value, Binding);
}
