//
//  DataBaseTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/15.
//
//

#import <XCTest/XCTest.h>
#include "DataBase.h"
#include "Dao.h"
#include "TTestTable.h"

@interface DataBaseTestCase : XCTestCase

@end

@implementation DataBaseTestCase

- (void)setUp {
    [super setUp];
}

- (void)tearDown {
    [super tearDown];
}

- (void)test1FindByName {
    Dao<TTestTable>* dao = DataBase::getInstance()->findByName<TTestTable>("TTestTable");
    bool isNull = dao == NULL ? true : false;
    XCTAssertFalse(isNull);
    dao = DataBase::getInstance()->findByName<TTestTable>("AnyNameDao");
    isNull = dao == NULL ? true : false;
    XCTAssertTrue(isNull);
}

- (void)test2Save {
    Dao<TTestTable>* dao = DataBase::getInstance()->findByName<TTestTable>("TTestTable");
    for (int i=0;i<10;i++) {
        TTestTable record;
        dao->save(record);
    }
    XCTAssertEqual(10, dao->count());
}

- (void)test3Count {
    Dao<TTestTable>* dao = DataBase::getInstance()->findByName<TTestTable>("TTestTable");
    XCTAssertEqual(10, dao->count());
}


- (void)test4Clear {
    DataBase::getInstance()->clear();
    Dao<TTestTable>* dao = DataBase::getInstance()->findByName<TTestTable>("TTestTable");
    XCTAssertEqual(0, dao->count());
}

@end
