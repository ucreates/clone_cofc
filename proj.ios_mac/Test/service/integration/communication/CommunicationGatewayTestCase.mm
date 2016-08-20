//
//  CommunicationGatewayTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/23.
//
//
#import <XCTest/XCTest.h>
#include "CommunicationGateway.h"
#include "BaseCallback.h"
@interface CommunicationGatewayTestCase : XCTestCase
@end
@implementation CommunicationGatewayTestCase
- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}
- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}
- (void)test1Request {
    BaseCallback* callback = new BaseCallback();
    //コールバックなし
    CommunicationGateway* cg = CommunicationGateway::getInstance();
    cg->request("https://www.google.co.jp/");
    //コールバックあり
    cg->request("https://www.google.co.jp/", callback);
}
@end
