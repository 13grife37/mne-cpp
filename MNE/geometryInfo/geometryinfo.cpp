//=============================================================================================================
/**
* @file     geometryinfo.cpp
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
* @brief    GeometryInfo class definition.
*
*/


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include "geometryinfo.h"


//*************************************************************************************************************
//=============================================================================================================
// INCLUDES
//=============================================================================================================

#include <cmath>
#include <fstream>

//*************************************************************************************************************
//=============================================================================================================
// QT INCLUDES
//=============================================================================================================

#include <QFile>

//*************************************************************************************************************
//=============================================================================================================
// Eigen INCLUDES
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// USED NAMESPACES
//=============================================================================================================

using namespace SWP;


//*************************************************************************************************************
//=============================================================================================================
// DEFINE GLOBAL METHODS
//=============================================================================================================


//*************************************************************************************************************
//=============================================================================================================
// DEFINE MEMBER METHODS
//=============================================================================================================


QSharedPointer<MatrixXd> GeometryInfo::scdc(const MNEBemSurface &inSurface, const QVector<qint32> &vertSubSet)
{


    ////////////////////////////////////
    //qint32 n = inSurface.n.length();
    std::cout << "||" << " lol "<< "||" << std::endl;
    QSharedPointer<MatrixXd> ptr = QSharedPointer<MatrixXd>::create(inSurface.rr.rows(), inSurface.rr.rows());
    //const QList<QPair<int, QVector<int> > > &neighborMap = inSurface.neighbor_vert;

    // convention: first dimension in distance table is "from", second dimension "to"

    //QPair<int, QVector<int> > tempPair;
    //int tempID;
    std::cout << inSurface.rr.rows() <<std::endl;
    std::cout << inSurface.rr.cols() <<std::endl;
    for (size_t i = 0; i < inSurface.rr.rows(); ++i) {
        //std::cout << inSurface.rr.rows() <<std::endl;
        float xFrom = inSurface.rr(i, 0);
        float yFrom = inSurface.rr(i, 1);
        float zFrom = inSurface.rr(i, 2);
        //Vector3f currentVertex = inSurface.rr(i)
        for (size_t j = 0; j < inSurface.rr.rows(); ++j) {


            float xTo = inSurface.rr(j, 0);
            float yTo = inSurface.rr(j, 1);
            float zTo = inSurface.rr(j, 2);
            (*ptr)(i, j) = sqrt(pow(xTo - xFrom, 2) + pow(yTo - yFrom, 2) + pow(zTo - zFrom, 2));
        }
    }
    std::cout << *ptr <<endl;
    std::ofstream file;
    file.open("./matrixDump.txt");
    file << *ptr;
    return ptr;
}
//*************************************************************************************************************

QSharedPointer<MatrixXd> GeometryInfo::scdc(const MNEBemSurface  &inSurface, double cancelDistance, const QVector<qint32> &vertSubSet)
{
    QSharedPointer<MatrixXd> outputMat = QSharedPointer<MatrixXd>::create();
    return outputMat;
}
//*************************************************************************************************************

QSharedPointer<QVector<qint32>> GeometryInfo::projectSensor(const MNEBemSurface &inSurface, const QVector<Vector3d> &sensorPositions)
{
    QSharedPointer<QVector<qint32>> outputArray = QSharedPointer<QVector<qint32>>::create();
    return outputArray;
}
//*************************************************************************************************************



