//
//  DaoTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/15.
//
//
#import <XCTest/XCTest.h>
#include "Dao.h"
#include "Key.h"
#include "TTestTable.h"
#include "ConditionExpression.h"
#include "AndExpression.h"
#include "OrExpression.h"
#include "OrderByExpression.h"
#include "LimitExpression.h"
#include "Field.h"
#include "ConvertUtility.h"
@interface DaoTestCase : XCTestCase
@end
@implementation DaoTestCase
- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}
- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}
- (void)test1Save {
    Dao<TTestTable> dao;
    dao.save();
    dao.save();
    dao.save();
    dao.save();
    XCTAssertEqual(dao.count(), 1);
}
- (void)test2Save {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    //すでに存在するレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record = dao.findBy(i + 1);
        bool ret = dao.save(record);
        XCTAssertFalse(ret);
    }
    XCTAssertEqual(dao.count(), 10);
}
- (void)test3findBy {
    Dao<TTestTable> dao;
    bool ret = dao.save();
    XCTAssertTrue(ret);
    TTestTable record1 = dao.findBy(1);
    XCTAssertEqual(record1.id, 1);
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    for (int i = 0; i < 10; i++) {
        TTestTable record = dao.findBy(i + 1);
        XCTAssertEqual(record.id, i + 1);
    }
}
- (void)test4findBy {
    Dao<TTestTable> dao;
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    for (int i = 0; i < 10; i++) {
        int index = i + 1;
        Key key;
        key.add("id", index);
        TTestTable record = dao.findBy(key);
        XCTAssertEqual(record.id, index);
    }
}
- (void)test5Update {
    Dao<TTestTable> dao;
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        bool ret = dao.update(record);
        XCTAssertFalse(ret);
        ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    for (int i = 0; i < 10; i++) {
        TTestTable record = dao.findBy(i + 1);
        record.complete = true;
        bool ret = dao.update(record);
        XCTAssertTrue(ret);
    }
    for (int i = 0; i < 10; i++) {
        TTestTable record = dao.findBy(i + 1);
        XCTAssertTrue(record.complete);
    }
}
- (void)test6Remove {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    XCTAssertEqual(dao.count(), 10);
    for (int i = 0; i < 10; i++) {
        TTestTable record = dao.findBy(i + 1);
        bool ret = dao.remove(record);
        XCTAssertTrue(ret);
    }
    XCTAssertEqual(dao.count(), 0);
}
- (void)test7FindFirst {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    TTestTable record = dao.findFirst();
    XCTAssertEqual(record.testIntVal, 1000);
}
- (void)test8FindLast {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    TTestTable record = dao.findLast();
    XCTAssertEqual(record.testIntVal, 10 * 1000);
}
- (void)test9FindNext {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    //現在のレコードの一つ次のレコードを参照する。
    int index = 2;
    while (!dao.isEor()) {
        TTestTable record = dao.findNext();
        XCTAssertEqual(record.testIntVal, index * 1000);
        index++;
    }
    XCTAssertTrue(dao.isEor());
}
- (void)test10FindPrevious {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    //現在のレコードの一つ前のレコードを参照する。
    while (!dao.isEor()) {
        TTestTable record = dao.findNext();
    }
    XCTAssertTrue(dao.isEor());
    int index = 9;
    while (!dao.isFor()) {
        TTestTable record = dao.findPrevious();
        XCTAssertEqual(record.testIntVal, index * 1000);
        index--;
    }
    XCTAssertTrue(dao.isFor());
}
- (void)test11FindBy {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    Field<int> field(1000);
    ConditionExpression cep = ConditionExpression("testIntVal", "==", &field);
    std::vector<TTestTable> result = dao.findBy(&cep);
    XCTAssertEqual(1, result.size());
    cep = ConditionExpression("testIntVal", "<", &field);
    result = dao.findBy(&cep);
    XCTAssertEqual(0, result.size());
    cep = ConditionExpression("testIntVal", "<=", &field);
    result = dao.findBy(&cep);
    XCTAssertEqual(1, result.size());
    cep = ConditionExpression("testIntVal", ">", &field);
    result = dao.findBy(&cep);
    XCTAssertEqual(9, result.size());
    cep = ConditionExpression("testIntVal", ">=", &field);
    result = dao.findBy(&cep);
    XCTAssertEqual(10, result.size());
    dao.clear();
}
- (void)test12FindBy {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        record.complete = 0 == (i % 2) ? true : false;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    Field<int> field1(1000);
    AndExpression expression;
    expression.addCondition(ConditionExpression("testIntVal", ">=", &field1));
    std::vector<TTestTable> result = dao.findBy(&expression);
    XCTAssertEqual(10, result.size());
    Field<bool> field2(true);
    expression.addCondition(ConditionExpression("complete", "==", &field2));
    result = dao.findBy(&expression);
    XCTAssertEqual(5, result.size());
    dao.clear();
}
- (void)test13FindBy {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        record.complete = 0 == (i % 2) ? true : false;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    Field<int> field1(1000);
    OrExpression expression;
    expression.addCondition(ConditionExpression("testIntVal", ">=", &field1));
    std::vector<TTestTable> result = dao.findBy(&expression);
    XCTAssertEqual(10, result.size());
    Field<bool> field2(true);
    expression.addCondition(ConditionExpression("complete", "==", &field2));
    result = dao.findBy(&expression);
    XCTAssertEqual(10, result.size());
    dao.clear();
}
- (void)test14FindBy {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        record.complete = 0 == (i % 2) ? true : false;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    Field<int> field1(1000);
    ConditionExpression expression = ConditionExpression("testIntVal", ">=", &field1);
    OrderByExpression oexp1("testIntVal", OrderByExpression::OrderType::Asc);
    std::vector<TTestTable> result = dao.findBy(&expression, &oexp1);
    for (int i = 0; i < 10; i++) {
        int id = i + 1;
        XCTAssertEqual(id, result[i].id);
    }
    OrderByExpression oexp2("testIntVal", OrderByExpression::OrderType::Desc);
    result = dao.findBy(&expression, &oexp2);
    for (int i = 0; i < 10; i++) {
        int id = 10 - i;
        XCTAssertEqual(id, result[i].id);
    }
    dao.clear();
}
- (void)test15FindBy {
    Dao<TTestTable> dao;
    //存在しないレコードをsave
    for (int i = 0; i < 10; i++) {
        TTestTable record;
        record.testIntVal = (i + 1) * 1000;
        record.complete = 0 == (i % 2) ? true : false;
        bool ret = dao.save(record);
        XCTAssertTrue(ret);
    }
    Field<int> field1(1000);
    ConditionExpression expression = ConditionExpression("testIntVal", ">=", &field1);
    LimitExpression lexp1(3);
    std::vector<TTestTable> result = dao.findBy(&expression, NULL, &lexp1);
    XCTAssertEqual(3, result.size());
    LimitExpression lexp2(7);
    result = dao.findBy(&expression, NULL, &lexp2);
    XCTAssertEqual(7, result.size());
    dao.clear();
}
@end
