//
//  GeographicDataStreamTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/30.
//
//
#import <XCTest/XCTest.h>
#include "GeographicNodeSize.h"
#include "GeographicDataStream.h"
#include "GeographicDataBaseFormat.h"
@interface GeographicDataStreamTestCase : XCTestCase
@end
@implementation GeographicDataStreamTestCase
- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}
- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}
- (void)test1Write {
    GeographicDataStream* stream = new GeographicDataStream();
    // bool ret = stream->write("");
    // XCTAssertTrue(ret);
}
- (void)test2Read {
    GeographicDataStream* stream = new GeographicDataStream();
    // std::vector<GeographicDataBaseFormat*> ret = stream->read("");
    //マップデータフォーマット総数:+1はGeographicDataHeaderの数
    // long totalCount = GeographicNodeSize::MAX_COORDINATE_X * GeographicNodeSize::MAX_COORDINATE_Y * GeographicNodeSize::MAX_COORDINATE_Z + 1;
    // XCTAssertEqual(totalCount,ret.size());
}
@end
