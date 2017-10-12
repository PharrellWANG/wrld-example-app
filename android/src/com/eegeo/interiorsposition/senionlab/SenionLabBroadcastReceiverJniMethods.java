// Copyright eeGeo Ltd (2012-2017), All Rights Reserved

package com.eegeo.interiorsposition.senionlab;

public class SenionLabBroadcastReceiverJniMethods
{
    public static native void DidUpdateLocation(long nativeCallerPointer,
                                                double latitude,
                                                double longitude,
                                                String floorId);

    public static native void SetIsAuthorized(long nativeCallerPointer, boolean isAuthorized);
    
    public static native void SetInteriorIdFromMapKey(long nativeCallerPointer, String mapKey);
    
    public static native void SetIsConnected(long nativeCallerPointer, boolean isConnected);
}
