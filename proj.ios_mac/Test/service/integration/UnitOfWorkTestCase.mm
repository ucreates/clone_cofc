//
//  UnitOfWorkTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/23.
//
//

#import <XCTest/XCTest.h>
#include "UnitOfWork.h"
#include "DataBase.h"
#include "Dao.h"
#include "TTestTable.h"

@interface UnitOfWorkTestCase : XCTestCase

@end

@implementation UnitOfWorkTestCase

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)test1Add {
    DataBase* db = DataBase::getInstance();
    UnitOfWork<TTestTable>* uow = new UnitOfWork<TTestTable>();
    for (int i=0;i<10;i++) {
        TTestTable record;
        record.testIntVal = i;
        bool ret = uow->registerAddRecord(record);
        XCTAssertTrue(ret);
    }
    bool ret = uow->add();
    XCTAssertTrue(ret);
    Dao<TTestTable>* dao = db->findByName<TTestTable>("TTestTable");
    XCTAssertEqual(dao->count(), 10);
}

- (void)test2Update {
    DataBase* db = DataBase::getInstance();
    Dao<TTestTable>* dao = db->findByName<TTestTable>("TTestTable");
    UnitOfWork<TTestTable>* uow = new UnitOfWork<TTestTable>();
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        record.testIntVal *= -1;
        uow->registerUpdateRecord(record);
    }
    bool ret = uow->update();
    XCTAssertTrue(ret);
    XCTAssertEqual(dao->count(), 10);
    
    int index = -1;
    while(!dao->isEor()) {
        TTestTable record = dao->findNext();
        XCTAssertEqual(record.testIntVal, index);
        index--;
    }
}

- (void)test3Remove {
    DataBase* db = DataBase::getInstance();
    Dao<TTestTable>* dao = db->findByName<TTestTable>("TTestTable");
    UnitOfWork<TTestTable>* uow = new UnitOfWork<TTestTable>();
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        uow->registerRemoveRecord(record);
    }
    bool ret = uow->remove();
    XCTAssertTrue(ret);
    XCTAssertEqual(dao->count(), 0);
}

- (void)test4Clear {
    UnitOfWork<TTestTable>* uow = new UnitOfWork<TTestTable>();
    for (int i=0;i<10;i++) {
        TTestTable record;
        uow->registerAddRecord(record);
        uow->registerUpdateRecord(record);
        uow->registerRemoveRecord(record);
    }
    uow->clear();
}

- (void)test5Commit {
    DataBase* db = DataBase::getInstance();
    db->clear();
    db = DataBase::getInstance();
    Dao<TTestTable>* dao = db->findByName<TTestTable>("TTestTable");
    UnitOfWork<TTestTable>* uow = new UnitOfWork<TTestTable>();
    
    //元データ:20件
    for (int i=0;i<20;i++) {
        TTestTable record;
        record.testIntVal = i;
        dao->save(record);
    }
    
    //新規追加:10件
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record;
        record.testIntVal = index * 10;
        uow->registerAddRecord(record);
    }

    //更新:10件
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        record.testIntVal = index * 1000;
        uow->registerUpdateRecord(record);
    }

    //削除:10件
    for (int i=10;i<20;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        uow->registerRemoveRecord(record);
    }
    
    //コミット
    bool ret = uow->commit();
    XCTAssertTrue(ret);
    XCTAssertEqual(dao->count(), 20);
    
    //更新確認
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        XCTAssertEqual(record.testIntVal, index * 1000);
    }

    //追加確認
    for (int i=20;i<30;i++) {
        int id = i + 1;
        int index = id - 20;
        TTestTable record = dao->findBy(id);
        XCTAssertEqual(record.testIntVal, index * 10);
    }
    
    delete uow;
}

- (void)test6Rollback {
    DataBase* db = DataBase::getInstance();
    db->clear();
    db = DataBase::getInstance();
    Dao<TTestTable>* dao = db->findByName<TTestTable>("TTestTable");
    UnitOfWork<TTestTable>* uow = new UnitOfWork<TTestTable>();
    
    //元データ:20件
    for (int i=0;i<20;i++) {
        TTestTable record;
        record.testIntVal = i;
        dao->save(record);
    }
    
    //新規追加:10件
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record;
        record.testIntVal = index * 10;
        uow->registerAddRecord(record);
    }
    
    //更新:10件
    for (int i=0;i<10;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        record.testIntVal = index * 1000;
        uow->registerUpdateRecord(record);
    }
    
    //削除:10件
    for (int i=10;i<20;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        uow->registerRemoveRecord(record);
    }
    
    //コミット
    bool ret = uow->commit();
    XCTAssertTrue(ret);
    XCTAssertEqual(dao->count(), 20);
    
    //ロールバック
    ret = uow->rollback();
    XCTAssertTrue(ret);
    XCTAssertEqual(dao->count(), 20);
    
    for (int i=0;i<20;i++) {
        int index = i + 1;
        TTestTable record = dao->findBy(index);
        XCTAssertEqual(record.testIntVal, i);
    }
    
    delete uow;
}

@end
