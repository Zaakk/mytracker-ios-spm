//
//  MROfferRequestBuilder.h
//  MyTrackerSDK
//
//  Created by Alexander Zakatnov on 27.04.2021.
//  Copyright © 2021 Mail.Ru Group. All rights reserved.
//

#import <Foundation/Foundation.h>
#import <MyTrackerSDK/MRFinal.h>
#import <MyTrackerSDK/MROfferRequest.h>

@protocol MROfferRequestOnCompleteDelegate;

@class MROfferRequest;

NS_ASSUME_NONNULL_BEGIN

/**
 Builder-class for MROfferRequest
 */
MR_FINAL
@interface MROfferRequestBuilder : NSObject

/**
 @discussion: Creates new instance of class NOTE: For efficiency you could create one instance per userId
 
 @param userId custom user identifier
 
 @return Factory object for creating builders with defined userId
*/
+ (instancetype)newBuilderWithUserId:(NSString *)userId NS_SWIFT_NAME(newBuilder(userId:));

/**
 @discussion Sets the value of placementId
 
 @param placementId New value of user identifier
 
 @return Instance of MROfferRequestBuilder
 */
- (instancetype)withPlacementIds:(NSArray<NSString *> * _Nullable)placementId NS_SWIFT_NAME(with(placementIds:));

/**
 @discussion Determines should recommendation be reset in next request
 
 @param reset Reset parameter
 
 @return Instance of MROfferRequestBuilder
 */
- (instancetype)withReset:(MROfferRequestReset)reset NS_SWIFT_NAME(with(reset:));

/**
 @discussion Sets the custom data
 
 @param data New value of custom data
 
 @return Instance of MROfferRequestBuilder
 */
- (instancetype)withData:(NSString * _Nullable)data NS_SWIFT_NAME(with(data:));

/**
 @discussion Delegate which will get response
 
 @param delegate Instance that implements MROfferRequestOnCompleteDelegate protocol
 
 @return Instance of MROfferRequestBuilder
 */
- (instancetype)withRequestDelegate:(id <MROfferRequestOnCompleteDelegate> _Nullable)delegate NS_SWIFT_NAME(with(requestDelegate:));

/**
 @discussion Queue that will be using to call delegate's methods
 
 @param queue Instance of NSOperationQueue
 
 @return Instance of MROfferRequestBuilder
 */
- (instancetype)withQueue:(NSOperationQueue *)queue NS_SWIFT_NAME(with(queue:));

/**
 @discussion Builds MROfferRequest instance to make a request for offers
 
 @return Instance of MROfferRequest
 */
- (MROfferRequest *)build NS_SWIFT_NAME(build());

@end

NS_ASSUME_NONNULL_END
