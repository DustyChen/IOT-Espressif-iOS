//
//  ESPActionDeviceEsptouch.h
//  suite
//
//  Created by 白 桦 on 7/29/16.
//  Copyright © 2016 白 桦. All rights reserved.
//

#import <Foundation/Foundation.h>
#import "ESPTouchDelegate.h"

@interface ESPActionDeviceEsptouch : NSObject
/**
 * Note: !!!Don't call the task at UI Main Thread or RuntimeException will be thrown Execute the Esptouch Task and
 * return the result
 *
 * Smart Config v2.4 support the API
 *
 * It will be blocked until the client receive result count >= expectTaskResultCount. If it fail, it will return one
 * fail result will be returned in the list. If it is cancelled while executing, if it has received some results,
 * all of them will be returned in the list. if it hasn't received any results, one cancel result will be returned
 * in the list.
 *
 * @param expectTaskResultCount the expect result count(if expectTaskResultCount <= 0, expectTaskResultCount =
 *            Integer.MAX_VALUE)
 * @param apSsid the Ap's ssid
 * @param apBssid the Ap's bssid
 * @param apPassword the Ap's password
 * @param isSsidHidden whether the Ap's ssid is hidden
 * @param timeoutMillisecond(it should be >= 15000+6000) millisecond of total timeout
 *
 * @return the array of ESPTouchResult
 */

-(NSArray *) doActionDeviceEsptouchResultCount:(int)expectTaskResultCount ApSsid:(NSString *)apSsid ApBssid:(NSString *)apBssid ApPassword:(NSString *)apPassword IsSsidHidden:(BOOL)isSsidHidden TimeoutMillisecond:(int)timeoutMillisecond;

/**
 * Note: !!!Don't call the task at UI Main Thread or RuntimeException will be thrown Execute the Esptouch Task and
 * return the result
 *
 * Smart Config v2.4 support the API
 *
 * It will be blocked until the client receive result count >= expectTaskResultCount. If it fail, it will return one
 * fail result will be returned in the list. If it is cancelled while executing, if it has received some results,
 * all of them will be returned in the list. if it hasn't received any results, one cancel result will be returned
 * in the list.
 *
 * @param expectTaskResultCount the expect result count(if expectTaskResultCount <= 0, expectTaskResultCount =
 *            Integer.MAX_VALUE)
 * @param apSsid the Ap's ssid
 * @param apBssid the Ap's bssid
 * @param apPassword the Ap's password
 * @param isSsidHidden whether the Ap's ssid is hidden
 * @param timeoutMillisecond(it should be >= 15000+6000) millisecond of total timeout
 * @param esptouchListener when one device is connected to the Ap, it will be called back
 *
 * @return the array of ESPTouchResult
 */
-(NSArray *) doActionDeviceEsptouchResultCount:(int)expectTaskResultCount ApSsid:(NSString *)apSsid ApBssid:(NSString *)apBssid ApPassword:(NSString *)apPassword IsSsidHidden:(BOOL)isSsidHidden TimeoutMillisecond:(int)timeoutMillisecond Delegate:(id<ESPTouchDelegate>)delegate;

/**
 * the same as this{@link #doActionDeviceEsptouch(int, String, String, String, boolean, int)}, except
 * timeoutMillisecond = 60000
 *
 * @param expectTaskResultCount the expect result count(if expectTaskResultCount <= 0, expectTaskResultCount =
 *            Integer.MAX_VALUE)
 * @param apSsid the Ap's ssid
 * @param apBssid the Ap's bssid
 * @param apPassword the Ap's password
 * @param isSsidHidden whether the Ap's ssid is hidden
 *
 * @return the array of ESPTouchResult
 */
-(NSArray *) doActionDeviceEsptouchResultCount:(int)expectTaskResultCount ApSsid:(NSString *)apSsid ApBssid:(NSString *)apBssid ApPassword:(NSString *)apPassword IsSsidHidden:(BOOL)isSsidHidden;

/**
 * the same as this{@link #doActionDeviceEsptouch(int, String, String, String, boolean, int)}, except
 * timeoutMillisecond = 60000
 *
 * @param expectTaskResultCount the expect result count(if expectTaskResultCount <= 0, expectTaskResultCount =
 *            Integer.MAX_VALUE)
 * @param apSsid the Ap's ssid
 * @param apBssid the Ap's bssid
 * @param apPassword the Ap's password
 * @param isSsidHidden whether the Ap's ssid is hidden
 * @param esptouchListener when one device is connected to the Ap, it will be called back
 *
 * @return the array of ESPTouchResult
 */
-(NSArray *) doActionDeviceEsptouchResultCount:(int)expectTaskResultCount ApSsid:(NSString *)apSsid ApBssid:(NSString *)apBssid ApPassword:(NSString *)apPassword IsSsidHidden:(BOOL)isSsidHidden Delegate:(id<ESPTouchDelegate>)delegate;

/**
 * check whether the Action Device Esptouch is cancelled
 *
 * @return whether the Action Device Esptouch is cancelled
 */
-(BOOL) isCancelled;

/**
 * cancel the action
 */
-(void) cancel;

/**
 * check whether exist Action Device Esptouch running
 *
 * @return whether exist Action Device Esptouch running
 */
-(BOOL) isExecuted;

/**
 * finish esptouch instantly
 */
-(void) done;

/**
 * check whether the esptouch is done
 *
 * @return whether the esptouch is done
 */
-(BOOL) isDone;
@end
