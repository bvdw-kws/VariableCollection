// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0


#include "VariableCollectionFunctionLibrary.h"

#include "Utility/Collection/VariableCollectionUtils.h"

float UVariableCollectionFunctionLibrary::GetVariableCollectionFloatValue(const FVariableCollectionFloat& Variable)
{
	return Variable.GetValue();
}

bool UVariableCollectionFunctionLibrary::GetVariableCollectionBoolValue(const FVariableCollectionBool& Variable)
{
	return Variable.GetValue();
}

int32 UVariableCollectionFunctionLibrary::GetVariableCollectionIntValue(const FVariableCollectionInt& Variable)
{
	return Variable.GetValue();
}

FVector UVariableCollectionFunctionLibrary::GetVariableCollectionVectorValue(const FVariableCollectionVector& Variable)
{
	return Variable.GetValue();
}

FRotator UVariableCollectionFunctionLibrary::GetVariableCollectionRotatorValue(const FVariableCollectionRotator& Variable)
{
	return Variable.GetValue();
}

UCurveFloat* UVariableCollectionFunctionLibrary::GetVariableCollectionCurveFloatValue(
	const FVariableCollectionCurveFloat& Variable)
{
	return Variable.GetValue();
}

FVariableCollectionFloat UVariableCollectionFunctionLibrary::MakeVariableCollection_Float(const FName Binding, float DefaultValue)
{
	FVariableCollectionFloat Result(DefaultValue);
	Result.SetFromVariableBinding(Binding);
	return Result;
}

FVariableCollectionInt UVariableCollectionFunctionLibrary::MakeVariableCollection_Int(const FName Binding, int32 DefaultValue)
{
	FVariableCollectionInt Result(DefaultValue);
	Result.SetFromVariableBinding(Binding);
	return Result;
}

FVariableCollectionBool UVariableCollectionFunctionLibrary::MakeVariableCollection_Bool(const FName Binding, bool DefaultValue)
{
	FVariableCollectionBool Result(DefaultValue);
	Result.SetFromVariableBinding(Binding);
	return Result;
}

FVariableCollectionVector UVariableCollectionFunctionLibrary::MakeVariableCollection_Vector(const FName Binding, FVector DefaultValue)
{
	FVariableCollectionVector Result(DefaultValue);
	Result.SetFromVariableBinding(Binding);
	return Result;
}

FVariableCollectionRotator UVariableCollectionFunctionLibrary::MakeVariableCollection_Rotator(const FName Binding,
	FRotator DefaultValue)
{
	FVariableCollectionRotator Result(DefaultValue);
	Result.SetFromVariableBinding(Binding);
	return Result;
}

FVariableCollectionCurveFloat UVariableCollectionFunctionLibrary::MakeVariableCollection_CurveFloat(const FName Binding,
	UCurveFloat* DefaultValue)
{
	FVariableCollectionCurveFloat Result(DefaultValue);
	Result.SetFromVariableBinding(Binding);
	return Result;
}

TArray<FName> UVariableCollectionFunctionLibrary::GetFloatPropertyNames()
{
	return VariableCollection::Utils::GetPropertyNames([](const FProperty* Property)
	{		
		if (const FNumericProperty* FloatProperty = CastField<FNumericProperty>(Property))
		{
			return true;
		}
		return false;
	});
}

TArray<FName> UVariableCollectionFunctionLibrary::GetIntPropertyNames()
{
	return VariableCollection::Utils::GetPropertyNames([](const FProperty* Property)
	{		
		if (const FNumericProperty* FloatProperty = CastField<FNumericProperty>(Property))
		{
			return true;
		}
		return false;
	});
}

TArray<FName> UVariableCollectionFunctionLibrary::GetBoolPropertyNames()
{
	return VariableCollection::Utils::GetPropertyNames([](const FProperty* Property)
	{
		if (const FBoolProperty* BoolProperty = CastField<FBoolProperty>(Property))
		{
			return true;
		}
		return false;
	});
}

TArray<FName> UVariableCollectionFunctionLibrary::GetVectorPropertyNames()
{
	return VariableCollection::Utils::GetPropertyNames([](const FProperty* Property)
	{		
		if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
		{
			return StructProperty->Struct == TBaseStructure<FVector>::Get();
		}
		return false;
	});
}

TArray<FName> UVariableCollectionFunctionLibrary::GetRotatorPropertyNames()
{
	return VariableCollection::Utils::GetPropertyNames([](const FProperty* Property)
	{		
		if (const FStructProperty* StructProperty = CastField<FStructProperty>(Property))
		{
			return StructProperty->Struct == TBaseStructure<FRotator>::Get();
		}
		return false;
	});
}

TArray<FName> UVariableCollectionFunctionLibrary::GetCurveFloatPropertyNames()
{
	return VariableCollection::Utils::GetPropertyNames([](const FProperty* Property)
	{		
		if (const FObjectPropertyBase* ObjProp = CastField<FObjectPropertyBase>(Property))
		{
			return ObjProp && ObjProp->PropertyClass == UCurveFloat::StaticClass();
		}
		return false;
	});
}
