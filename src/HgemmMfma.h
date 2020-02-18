#pragma once

#include "../inc/ff_utils.h"
#include "../inc/ff_gpu.h"
#include "HgemmMfmaKernelWriter.h"

using namespace feifei;

/************************************************************************/
/* solution����                                                          */
/************************************************************************/
class GemmMfmaAsmSolution : public SolutionCtrlBase
{
public:
	GemmMfmaAsmSolution() : SolutionCtrlBase("asm auto-gen") {}

protected:
	E_ReturnState generateKernel();
	E_ReturnState verifyResult();

private:
	T_GemmMfmaKernelParam kernelParam;
	GemmMfmaKernelWriter * kernelWriter;
};

/************************************************************************/
/* solver ����															*/
/************************************************************************/
class GemmMfmaSolver : public SolverCtrlBase
{
public:
	GemmMfmaSolver() : SolverCtrlBase() {}

protected:
	void generateSolver();
};

/************************************************************************/
/* �������                                                             */
/************************************************************************/
class GemmMfmaProblem : public ProblemCtrlBase
{
public:
	GemmMfmaProblem() : ProblemCtrlBase("mfma gemm")
	{
		solver = new GemmMfmaSolver();
	}

private:
	void initDataMem();
	void cpuCompute();
};
