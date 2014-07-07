#ifndef __NETSTRUCT_H__
#define __NETSTRUCT_H__

#include "Types.h"

/*
 * TNConnect is sent by client to server on the connection stage
 */
struct TNConnect
{
  ushort  itsTrainNum;  // Train number
  uchar   itsDirection; // Train direction
  ushort  itsSigNum;    // Number of signals on the client's route
  ushort  itsTrackId;   // Starting track id
  ushort  itsLocoType;  // Locomotive type
  uchar   itsCarNum;    // Number of cars
};

struct TNConnectAns
{
  uchar Req;
  uchar Code;
};

/*
 * TNCoords is sent by client to server to describe client's train attributes
 */
struct TNCoords
{
  ushort  itsTrainNum;    // Train number
  ushort  itsHeadTrackId; // Train's head track id
  ushort  itsTailTrackId; // Train's tails track id
  float   itsSpeed;       // Current speed
};

/*
 * TNSvetofor is sent by server to client to describe current state
 * of a signal.
 * Usually server sends all the singals' states array
 */
struct TNSvetofor
{
  ushort  itsId;    // Signal id
  uchar   itsValue; // Signal code
};

/*
 * TNTraf is sent by server to client to describe the traffic visible
 * to the client
*/
struct TNTraf
{
  ushort  itsTrainNum;    // Traffic train's number
  ushort  itsLocoType;    // Locomotive type
  ushort  itsHeadTrackId; // Head track id
  float   itsSpeed;       // Current speed
  uchar   itsCarNum;      // Number of cars
};

/*
 * TVisibles describes a pair of trains that are visible to each other
 */
struct TVisibles
{
  TTrain  *itsTrain[2]; // A pair of trains
};

#endif
