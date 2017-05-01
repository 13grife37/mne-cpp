//=============================================================================================================
/**
* @file     geometryinfo.cpp
* @author   Lars Debor <lars.debor@tu-ilmenau.de>;
*           Matti Hamalainen <msh@nmr.mgh.harvard.edu>
* @version  1.0
* @date     Month, Year
*
* @section  LICENSE
*
* Copyright (C) Year, Lars Debor and Matti Hamalainen. All rights reserved.
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

GeometryInfo::GeometryInfo()
{
}
//*************************************************************************************************************


QSharedPointer<MatrixXd> GeometryInfo::scdc(const MNEBemSurface &inSurface, const QVector<qint32> &vertSubSet)
{
    qint32 n = inSurface.neighbor_vert.length();
    std::cout << "||" << n << "||" << std::endl;
    QSharedPointer<MatrixXd> ptr = QSharedPointer<MatrixXd>(new MatrixXd(n, n));
    QList<QPair<int, QVector<int> > > neighborMap = inSurface.neighbor_vert;

    // convention: first dimension in distance table is "from", second dimension "to"

    QPair<int, QVector<int> > tempPair;
    int tempID;
    QVector<int> tempVector;
    for (size_t i = 0; i < n; i++) {
        tempPair = neighborMap.at(i);
        tempID = tempPair.first;
        tempVector = tempPair.second;
        for (size_t j = 0; j < tempVector.length(); j++) {
            float xFrom, yFrom, zFrom, xTo, yTo, zTo;
            xFrom = inSurface.rr(tempID, 0);
            yFrom = inSurface.rr(tempID, 1);
            zFrom = inSurface.rr(tempID, 2);
            xTo = inSurface.rr(tempVector.at(j), 0);
            yTo = inSurface.rr(tempVector.at(j), 1);
            zTo = inSurface.rr(tempVector.at(j), 2);
            (*ptr)(tempID, tempVector.at(j)) = sqrt(pow(xTo - xFrom, 2) + pow(yTo - yFrom, 2) + pow(zTo - zFrom, 2));
        }
    }
    std::ofstream file;
    file.open("./matrixDump.txt");
    file << (*ptr);
    return ptr;
}
//*************************************************************************************************************

QSharedPointer<MatrixXd> GeometryInfo::scdc(const MNEBemSurface  &inSurface, double cancelDistance, const QVector<qint32> &vertSubSet)
{
    return QSharedPointer<MatrixXd>(new MatrixXd);
}
//*************************************************************************************************************

QSharedPointer<QVector<qint32>> GeometryInfo::projectSensor(const MNEBemSurface &inSurface, const QVector<Vector3d> &sensorPositions)
{
return QSharedPointer<QVector<qint32>>(new QVector<qint32>);
}
//*************************************************************************************************************



