//
//  PointerMoveTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/21.
//
//

#import <XCTest/XCTest.h>
#include "Address.h"
@interface PointerMoveTestCase : XCTestCase

@end

@implementation PointerMoveTestCase

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)testExample {
    char valueList[10];
    
    for (int i=0;i<10;i++) {
        valueList[i]=i;
    }
    
    char* pointer = &valueList[0];
    
    for (int i=0;i<10;i++) {
        printf("pointer::%d\n",(char)(*pointer));
        pointer++;
    }

    for (int i=0;i<10;i++) {
        printf("pointer::%d\n",(char)(*pointer));
        pointer--;
    }
    
    // This is an example of a functional test case.
    // Use XCTAssert and related functions to verify your tests produce the correct results.
}

- (void)testPointerMove {
    int offset = 100;
    const char* pointer = NULL;
    Address* ad1 = new Address();
    ad1->x = 1;
    ad1->y = 2;
    ad1->z = 3;
    
    //ad1のアドレスが代入される
    pointer = (const char*)ad1;
    
    //ポインタムーブ
    pointer += offset;
    Address* ad2 = new Address();
    ad2->x = 4;
    ad2->y = 5;
    ad2->z = 6;
    //この時点でad2のアドレスが代入されるためポインタムーブした後の値とはことなるアドレス値となる
    pointer = (const char*)ad2;
    
    //ad1のものが見れるわけがない。
    pointer -= offset;
    const Address* rad1 = reinterpret_cast<const Address*>(pointer);
    
    //ad2のものは見れる。
    pointer += offset;
    const Address* rad2 = reinterpret_cast<const Address*>(pointer);
    
    //ad1のアドレスにする。
    pointer = (const char*)ad1;
    
    //ad1のものが見える。当たり前
    rad1 = reinterpret_cast<const Address*>(pointer);
    
    //ad2のは見えない。これも当たり前。なぜならad1をムーブした位置にad2はそもそも存在していないから。
    pointer += offset;
    rad2 = reinterpret_cast<const Address*>(pointer);
    
    return;
}

- (void)testPointerMove2 {
    const Address* pointer = NULL;
    Address* ad1 = new Address();
    ad1->x = 1;
    ad1->y = 2;
    ad1->z = 3;
    pointer = ad1;
    
    pointer++;
    Address* ad2 = new Address();
    ad2->x = 4;
    ad2->y = 5;
    ad2->z = 6;
    pointer = ad2;
    
    pointer--;
    const Address* rad1 = reinterpret_cast<const Address*>(pointer);
    pointer++;
    const Address* rad2 = reinterpret_cast<const Address*>(pointer);
    return;
}

- (void)testPointerStruct {
    char valueList[10];
    
    for (int i=0;i<10;i++) {
        valueList[i] = i;
    }
    
    
    return;
}

@end
