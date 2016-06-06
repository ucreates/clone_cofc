//
//  ServiceGatewayTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/24.
//
//

#import <XCTest/XCTest.h>
#include "ServiceGateway.h"
#include "BaseStrategy.h"

@interface ServiceGatewayTestCase : XCTestCase

@end

@implementation ServiceGatewayTestCase

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)test1FindByName {
    
    //存在しないサービス名
    BaseStrategy* strategy = ServiceGateway::getInstance()->findByName("service://service/strategy");
    bool isNull = strategy == NULL ? true : false;
    XCTAssertTrue(isNull);
    
    //プロトコル違う。
    strategy = ServiceGateway::getInstance()->findByName("http://base/init");
    isNull = strategy == NULL ? true : false;
    XCTAssertTrue(isNull);

    //存在しない戦略名
    strategy = ServiceGateway::getInstance()->findByName("service://base/none");
    isNull = strategy == NULL ? true : false;
    XCTAssertTrue(isNull);
    
    //正しい。
    strategy = ServiceGateway::getInstance()->findByName("service://base/init");
    isNull = strategy == NULL ? true : false;
    XCTAssertFalse(isNull);
}

- (void)test2Add {

    //存在しないサービス名
    bool ret = ServiceGateway::getInstance()->add("test",new BaseService());
    XCTAssertTrue(ret);
    
    //存在するサービス名
    ret = ServiceGateway::getInstance()->add("base",new BaseService());
    XCTAssertFalse(ret);
}

@end
