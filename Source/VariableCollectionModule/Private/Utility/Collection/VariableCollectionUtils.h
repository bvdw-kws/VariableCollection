// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "CoreMinimal.h"
#include "AssetRegistry/ARFilter.h"

namespace VariableCollection::Utils
{
	
extern TArray<FName> GetPropertyNames(const TFunction<bool(const FProperty*)>& PropertyEvaluatorFunc);

extern bool GetVariableCollectionProperty(const FName& Binding,
	TObjectPtr<UObject>& OutOwnerCollection, TFieldPath<FProperty>& OutProperty,
	const TFunction<bool(const FProperty*)>& PropertyEvaluatorFunc);
extern FString GetCollectionClassName_DEPRECATED(const UClass* Class);
	
} // namespace VariableCollection::Utils
