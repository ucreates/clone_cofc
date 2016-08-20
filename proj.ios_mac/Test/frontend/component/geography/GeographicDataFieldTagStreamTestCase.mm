//
//  GeographicDataFieldTagStreamTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2016/01/02.
//
//
#import <XCTest/XCTest.h>
#include "GeographicDataFieldTagStream.h"
#include "GeographicDataFieldTag.h"
#include "GeographicNodeManager.h"
#include "GeographicNode.h"
@interface GeographicDataFieldTagStreamTestCase : XCTestCase
@end
@implementation GeographicDataFieldTagStreamTestCase
- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}
- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}
- (void)testExample {
    std::ofstream* writer = new std::ofstream();
    writer->open("/Users/kotaromasamoto/Documents/src/clone_cofc/map.bin", std::ios::out | std::ios::binary | std::ios::trunc);
    if (!writer) {
        return;
    }
    GeographicNodeManager* gnm = GeographicNodeManager::getInstance();
    GeographicNode* node = gateway->findByAddress(10, 10);
    GeographicDataFieldTag tag(node);
    tag.build();
    GeographicDataFieldTagStream stream;
    stream.write(writer, &tag);
    writer->close();
    return;
}
@end
