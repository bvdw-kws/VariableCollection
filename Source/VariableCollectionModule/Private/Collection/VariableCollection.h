// Copyright (C) 2024 Van de Walle Bastien
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
// http://www.apache.org/licenses/LICENSE-2.0

#pragma once

#include "Engine/DataAsset.h"

#include "VariableCollection.generated.h"

/**
 * Class to hold variables that can be referenced from other assets.
 */
UCLASS(Abstract, Blueprintable)
class UVariableCollection : public UPrimaryDataAsset
{
	GENERATED_BODY()
	
protected:	
	virtual FPrimaryAssetId GetPrimaryAssetId() const override;
	
public:
	static const FPrimaryAssetType AssetType;	
};
