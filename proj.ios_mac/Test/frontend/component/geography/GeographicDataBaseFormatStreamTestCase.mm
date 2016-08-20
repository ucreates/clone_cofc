//
//  GeographicDataBaseFormatStreamTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2016/01/02.
//
//
#import <XCTest/XCTest.h>
#include "GeographicDataRecordHeaderStream.h"
#include "GeographicDataRecordHeader.h"
@interface GeographicDataBaseFormatStreamTestCase : XCTestCase
@end
@implementation GeographicDataBaseFormatStreamTestCase
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
    GeographicDataRecordHeader header;
    header.tagType = 0x01;
    header.geographicId = 0x1234;
    GeographicDataRecordHeaderStream stream;
    stream.write(writer, &header);
    writer->close();
    return;
}
@end
