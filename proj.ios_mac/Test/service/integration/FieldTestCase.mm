//
//  FieldTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2016/02/11.
//
//

#import <XCTest/XCTest.h>
#include <string>
#include "Field.h"

@interface FieldTestCase : XCTestCase

@end

@implementation FieldTestCase

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testEqual {
    Field<int> field1;
    field1.setValue(10);
    
    Field<int> field2;
    field2.setValue(10);
    
    XCTAssertTrue((field1.equal(&field2)));
    
    Field<int> field3;
    field3.setValue(20);

    XCTAssertFalse((field1.equal(&field3)));
    
    Field<std::string> field4;
    field4.setValue("value1");

    Field<std::string> field5;
    field4.setValue("value2");
    XCTAssertFalse((field4.equal(&field5)));
}

@end
