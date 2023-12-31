// Copyright Epic Games, Inc. All Rights Reserved.

/*=============================================================================
	MetalComputeShader.h: Metal RHI Compute Shader Class Definition.
=============================================================================*/

#pragma once


//------------------------------------------------------------------------------

#pragma mark - Metal RHI Compute Shader Class


class FMetalComputeShader : public TMetalBaseShader<FRHIComputeShader, SF_Compute>
{
public:
	FMetalComputeShader(TArrayView<const uint8> InCode, mtlpp::Library InLibrary = nil);
	virtual ~FMetalComputeShader();

	FMetalShaderPipeline* GetPipeline();
	mtlpp::Function GetFunction();

	// thread group counts
	int32 NumThreadsX;
	int32 NumThreadsY;
	int32 NumThreadsZ;

#if METAL_RHI_RAYTRACING
	/** Meta-data for function table binding indexes (UINT32_MAX if unavailable). */
	FMetalRayTracingHeader RayTracingBindings;
#endif // METAL_RHI_RAYTRACING

private:
	// the state object for a compute shader
	FMetalShaderPipeline* Pipeline;
};
