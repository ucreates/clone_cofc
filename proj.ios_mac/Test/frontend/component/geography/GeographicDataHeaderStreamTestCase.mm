//
//  GeographicDataRecordHeaderStreamTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2016/01/02.
//
//
#import <XCTest/XCTest.h>
#include "GeographicDataHeaderStream.h"
#include "GeographicDataHeader.h"
@interface GeographicDataHeaderStreamTestCase : XCTestCase
@end
@implementation GeographicDataHeaderStreamTestCase
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
    GeographicDataHeader header;
    header.build();
    GeographicDataHeaderStream stream;
    stream.write(writer, &header);
    writer->close();
    return;
}
@end
