// Filename LSLocateGasInterface.h
// Created on Nov 15, 2017 by Nishant Nangia
//
// Copyright (c) 2002-2017, Nishant Nangia and Amneet Bhalla
// All rights reserved.
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
//    * Redistributions of source code must retain the above copyright notice,
//      this list of conditions and the following disclaimer.
//
//    * Redistributions in binary form must reproduce the above copyright
//      notice, this list of conditions and the following disclaimer in the
//      documentation and/or other materials provided with the distribution.
//
//    * Neither the name of The University of North Carolina nor the names of
//      its contributors may be used to endorse or promote products derived from
//      this software without specific prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
// CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
// SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
// INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
// CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
// ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
// POSSIBILITY OF SUCH DAMAGE.


/////////////////////// INCLUDE GUARD ////////////////////////////////////

#ifndef included_LSLocateGasInterface
#define included_LSLocateGasInterface

///////////////////////////// INCLUDES ///////////////////////////////////
#include <ibamr/AdvDiffHierarchyIntegrator.h>

#include <ibtk/ibtk_utilities.h>

#include <tbox/Pointer.h>

namespace IBTK
{
class HierarchyMathOps;
}

/*
 * Pre processing call back function to be hooked into IBAMR:LInitStrategy
 */

void callLSLocateGasInterfaceCallbackFunction(int D_idx,
                                              SAMRAI::tbox::Pointer<IBTK::HierarchyMathOps> hier_math_ops,
                                              double time,
                                              bool initial_time,
                                              void* ctx);

class LSLocateGasInterface
{
    /*!
     * \brief class LSLocateGasInterface is a utility class which is used to identify
     * the circular interface for level set computations
     */
public:
    /*!
     * The only constructor of this class.
     */
    LSLocateGasInterface(const std::string& object_name,
                         SAMRAI::tbox::Pointer<IBAMR::AdvDiffHierarchyIntegrator> adv_diff_solver,
                         SAMRAI::tbox::Pointer<SAMRAI::pdat::CellVariable<NDIM, double> > ls_var,
                         const double init_height);

    /*!
     * Destructor for this class.
     */
    ~LSLocateGasInterface();

    /*!
     * Reinitialize the level set information
     */
    void setLevelSetPatchData(int D_idx,
                              SAMRAI::tbox::Pointer<IBTK::HierarchyMathOps> hier_math_ops,
                              const double time,
                              const bool initial_time);

    //////////////// PRIVATE /////////////////////////////

private:
    /*!
     * Default constructor is not implemented and should not be used.
     */
    LSLocateGasInterface();

    /*!
     * Default assignment operator is not implemented and should not be used.
     */
    LSLocateGasInterface& operator=(const LSLocateGasInterface& that);

    /*!
     * Default copy constructor is not implemented and should not be used.
     */
    LSLocateGasInterface(const LSLocateGasInterface& from);

    /*!
     * Name of this object.
     */
    std::string d_object_name;

    /*!
     * Pointer to the advection-diffusion solver
     */
    SAMRAI::tbox::Pointer<IBAMR::AdvDiffHierarchyIntegrator> d_adv_diff_solver;

    /*!
     * Level set variable
     */
    SAMRAI::tbox::Pointer<SAMRAI::pdat::CellVariable<NDIM, double> > d_ls_var;

    /*!
     * Initial level set information.
     */
    double d_init_height;
};

#endif // #ifndef included_LSLocateGasInterface
