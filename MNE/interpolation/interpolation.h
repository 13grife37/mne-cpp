//=============================================================================================================
/**
* @file     interpolation.h
* @author   Lars Debor <lars.debor@tu-ilmenau.de>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     Mai, 2017
*
* @section  LICENSE
*
* Copyright (C) 2017, Lars Debor and Matti Hamalainen. All rights reserved.
*
* Redistribution and use in source and binary forms, with or without modification, are permitted provided that
* the following conditions are met:
*     * Redistributions of source code must retain the above copyright notice, this list of conditions and the
*       following disclaimer.
*     * Redistributions in binary form must reproduce the above copyright notice, this list of conditions and
*       the following disclaimer in the documentation and/or other materials provided with the distribution.
*     * Neither the name of MNE-CPP authors nor the names of its contributors may be used
*       to endorse or promote products derived from this software without specific prior written permission.
*
* THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS" AND ANY EXPRESS OR IMPLIED
* WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A
* PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT,
* INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO,
* PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION)
* HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING
* NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
* POSSIBILITY OF SUCH DAMAGE.
*
*
* @brief     Interpolation class declaration.
*
*/

#ifndef SWP_INTERPOLATION_H
#define SWP_INTERPOLATION_H


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include"interpolation_global.h"

//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QSharedPointer>
#include <QVector>

//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================

#include<Eigen/Core>

//*************************************************************************************************************
//=============================================================================================================
// FORWARD DECLARATIONS
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// DEFINE NAMESPACE SWP
//=============================================================================================================

namespace SWP {

//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace Eigen;

//*************************************************************************************************************
//=============================================================================================================
// SWP FORWARD DECLARATIONS
//=============================================================================================================


//=============================================================================================================
/**
* Description of what this class is intended to do (in detail).
*
* @brief Brief description of this class.
*/

class INTERPOLATIONSHARED_EXPORT Interpolation
{

public:
    typedef QSharedPointer<Interpolation> SPtr;            /**< Shared pointer type for Interpolation. */
    typedef QSharedPointer<const Interpolation> ConstSPtr; /**< Const shared pointer type for Interpolation. */

    //=========================================================================================================
    /**
    * deleted default constructor (static class).
    */
    Interpolation() = delete;

    //=========================================================================================================
    /**
     * @brief createInterpolationMat
     * @param projectedSensors
     * @param distanceTable
     * @param interpolationType
     */
    static void createInterpolationMat(const QVector<qint32> &projectedSensors, const MatrixXd &distanceTable, qint32 interpolationType);

    //=========================================================================================================
    /**
     * @brief interpolateSignals
     * @param measurementData
     * @return
     */
    static QSharedPointer<VectorXd> interpolateSignals(const MatrixXd &measurementData);

    //=========================================================================================================
    /**
     * @brief clearInterpolateMatrix
     */
    static void clearInterpolateMatrix();

protected:

private:

    static QSharedPointer<MatrixXd> m_interpolationMatrix;   /**< Matrix holds the result of the last
                                                            createInterpolationMat() for further computations. */


};


//*************************************************************************************************************
//=============================================================================================================
// INLINE DEFINITIONS
//=============================================================================================================


} // namespace SWP

#endif // SWP_INTERPOLATION_H
