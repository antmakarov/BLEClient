//
//  AMPeripheral.h
//  BLEClient
//
//  Created by Anton Makarov on 20.02.2018.
//  Copyright © 2018 Anton Makarov. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <CoreBluetooth/CoreBluetooth.h>
#import "Periphery.h"
#import "AMService.h"
#import "BridgeDelegate.h"

@interface AMPeripheral : NSObject <CBPeripheralDelegate>

@property (nonatomic, readonly) CBPeripheral *CBPeripheral;
@property (nonatomic, readonly) NSMutableDictionary *services;
@property (nonatomic, readonly) NSInteger udpPort;
@property (nonatomic, weak) id <BleToUdpBridgeDelegate> delegate;

+ (instancetype)peripheralWithCBPeripheral:(CBPeripheral *)cbPeripheral;
- (instancetype)initWithCBPeripheral:(CBPeripheral *)cbPeripheral;

- (void)sendRequestData:(NSData *)requestData;
- (BOOL)isConnected;
- (void)getServiceInfo;

// Handling CBCentralManager callbacks.
- (void)didConnect;
- (void)discoverServices;
- (void)didFailToConnectWithError:(NSError *)error;
- (void)didDisconnectWithError:(NSError *)error;

@end