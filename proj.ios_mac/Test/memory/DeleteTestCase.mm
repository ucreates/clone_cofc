//
//  GeographicDataStreamTestCase.m
//  clone_cofc
//
//  Created by 柾本 耕太郎 on 2015/12/30.
//
//

#import <XCTest/XCTest.h>
//builder
#include "UIAssetBuilder.h"

//entity
#include "Parameter.h"

//sound asset
#include "BaseSoundAsset.h"
#include "SoundEffectAsset.h"
#include "BGMAsset.h"

//render asset
#include "BaseAsset.h"
#include "TextureAsset.h"
#include "AnimatorAsset.h"
#include "UIAsset.h"
#include "AssetManager.h"

//collider
#include "BaseCollider.h"
#include "RectCollider.h"
#include "CircleCollider.h"
#include "EllipseCollider.h"

//geography
#include "GeographicNode.h"
#include "GeographicNodeManager.h"
#include "GeographicNodeSize.h"
#include "GeographicNodeSlope.h"
#include "GeographicBuilder.h"

//property
#include "BaseBehaviourProperty.h"
#include "OrnamentBehaviourProperty.h"
#include "UIBehaviourProperty.h"
#include "UnitBehaviourProperty.h"
#include "WeaponBehaviourProperty.h"

//behaviour
#include "Basebehaviour.h"
#include "CannonBehaviour.h"
#include "DummyBarrierBehaviour.h"
#include "MortarBehaviour.h"
#include "TurretBehaviour.h"
#include "WoodFenceHBehaviour.h"
#include "WoodFenceVBehaviour.h"
#include "DummyNode5Behaviour.h"
#include "LoadingUIBehaviour.h"
#include "LogoUIBehaviour.h"
#include "ArcherBehaviour.h"
#include "BarbarianBehaviour.h"
#include "DummyUnitBehaviour.h"
#include "GiantBehaviour.h"
#include "GoblinBehaviour.h"
#include "TowerArcherBehaviour.h"
#include "WallBreakerBehaviour.h"
#include "ArrowBehaviour.h"
#include "CannonBulletBehaviour.h"
#include "MortarBulletBehaviour.h"
#include "GraveBehaviour.h"
#include "DummyNode1Behaviour.h"
#include "DummyNode2Behaviour.h"
#include "DummyNode3Behaviour.h"
#include "DummyNode4Behaviour.h"
#include "DummyNode5Behaviour.h"
#include "GrassBehaviour.h"
#include "GeographyEditorBehaviour.h"
#include "LoadingUIBehaviour.h"
#include "ArrowViewerBehaviour.h"
#include "AsterRouteSearchTestBehaviour.h"
#include "AstarRouteSearchViewerBehaviour.h"
#include "DijkstraRouteSearchTestBehaviour.h"
#include "DijkstraRouteSearchViewerBehaviour.h"
#include "GeographyTestUIBehaviour.h"
#include "ArrowBehaviour.h"
#include "CannonBulletBehaviour.h"
#include "MortarBulletBehaviour.h"

#include "BehaviourManager.h"
#include "BehaviourQueue.h"
#include "BehaviourIdManager.h"

//route
#include "BaseRouteSearch.h"
#include "AstarRouteSearch.h"
#include "DijkstraRouteSearch.h"
#include "ManhattanDistanceRouteSearch.h"
#include "BaseAstarHeuristic.h"
#include "AstarManhattanHeuristic.h"
#include "AstarTwoPointDistanceHeuristic.h"
#include "DijkstraGeographicNodeLink.h"
#include "DijkstraRouteSearch.h"

//notifier
#include "Notifier.h"
#include "NotifyManager.h"

//state
#include "FiniteStateMachine.h"
#include "CannonBehaviourAttackState.h"
#include "CannonBehaviourSearchState.h"
#include "CannonBehaviourDestroyState.h"
#include "CannonBehaviourTouchBeganState.h"
#include "CannonBehaviourTouchEndState.h"

#include "DummyBarrierDestroyState.h"

#include "ElixirTankBehaviourDestroyState.h"
#include "ElixirTankBehaviourDamageState.h"
#include "ElixirTankBehaviourTouchBeganState.h"
#include "ElixirTankBehaviourTouchEndState.h"

#include "GoldStrageBehaviourDestroyState.h"
#include "GoldStrageBehaviourDamageState.h"
#include "GoldStrageBehaviourTouchBeganState.h"
#include "GoldStrageBehaviourTouchEndState.h"

#include "MortarBehaviourAttackState.h"
#include "MortarBehaviourDestroyState.h"
#include "MortarBehaviourPauseState.h"
#include "MortarBehaviourTouchBeganState.h"
#include "MortarBehaviourTouchEndState.h"

#include "TurretBehaviourDestroyState.h"
#include "TurretBehaviourTouchBeganState.h"
#include "TurretBehaviourTouchEndState.h"

#include "WoodFenceHBehaviourDestroyState.h"
#include "WoodFenceHBehaviourTouchBeganState.h"
#include "WoodFenceHBehaviourTouchEndState.h"

#include "WoodFenceVBehaviourDestroyState.h"
#include "WoodFenceVBehaviourTouchBeganState.h"
#include "WoodFenceVBehaviourTouchEndState.h"

#include "DummyNode5BehaviourNormalState.h"
#include "DummyNode5BehaviourBlinkState.h"

#include "LoadingUIBehaviourLoadingState.h"
#include "LogoUIBehaviourFadeInState.h"

#include "ArcherBehaviourMoveState.h"
#include "ArcherBehaviourAttackState.h"
#include "ArcherBehaviourWinState.h"
#include "ArcherBehaviourLoseState.h"

#include "BarbarianBehaviourMoveState.h"
#include "BarbarianBehaviourAttackState.h"
#include "BarbarianBehaviourWinState.h"
#include "BarbarianBehaviourLoseState.h"

#include "DummyUnitBehaviourMoveState.h"
#include "DummyUnitBehaviourAttackState.h"

#include "GiantBehaviourMoveState.h"
#include "GiantBehaviourAttackState.h"
#include "GiantBehaviourWinState.h"
#include "GiantBehaviourLoseState.h"

#include "GoblinBehaviourMoveState.h"
#include "GoblinBehaviourAttackState.h"
#include "GoblinBehaviourWinState.h"
#include "GoblinBehaviourLoseState.h"

#include "TowerArcherBehaviourSearchState.h"
#include "TowerArcherBehaviourAttackState.h"
#include "TowerArcherBehaviourWinState.h"
#include "TowerArcherBehaviourLoseState.h"

#include "WallBreakerBehaviourMoveState.h"
#include "WallBreakerBehaviourAttackState.h"
#include "WallBreakerBehaviourWinState.h"
#include "WallBreakerBehaviourLoseState.h"

#include "ArrowBehaviourActiveBezier2DState.h"
#include "ArrowBehaviourActiveBezier3DState.h"
#include "ArrowBehaviourDestroyState.h"

#include "CannonBulletBehaviourActiveState.h"
#include "CannonBulletBehaviourDestroyState.h"

#include "MortarBulletBehaviourActiveState.h"
#include "MortarBulletBehaviourDestroyState.h"

#include "CommandManager.h"
#include "BaseCommand.h"
#include "UICommand.h"
#include "OrnamentCommand.h"
#include "WeaponCommand.h"
#include "UnitCommand.h"

@interface DeleteTestCase : XCTestCase

@end

@implementation DeleteTestCase

- (void)setUp {
    [super setUp];
    // Put setup code here. This method is called before the invocation of each test method in the class.
}

- (void)tearDown {
    // Put teardown code here. This method is called after the invocation of each test method in the class.
    [super tearDown];
}

- (void)test1Builder {
    UIAssetBuilder* builder = new UIAssetBuilder(NULL);
    delete builder;
}

- (void)test2SoundAsset {
    BaseSoundAsset* bsa = new BaseSoundAsset();
    delete bsa;

    SoundEffectAsset* sea = new SoundEffectAsset("");
    delete sea;

    BGMAsset* bgma = new BGMAsset("");
    delete bgma;

}

- (void)test3RenderAsset {
    BaseAsset* asset = new BaseAsset();
    delete asset;
    
    TextureAsset* tasset = new TextureAsset("img/weapon/cannon/cnannon_stand.png");
    delete tasset;

    AnimatorAsset* aasset = new AnimatorAsset("csb/animation/barrier/cannon",0);
    delete aasset;

    UIAsset* uasset = new UIAsset("csb/animation/barrier/cannon");
    delete uasset;
    
    AssetManager* am = new AssetManager();
    am->save("base",new BaseAsset());
    am->save("texture",new TextureAsset("img/weapon/cannon/cnannon_stand.png"));
    am->save("anime",new AnimatorAsset("csb/animation/barrier/cannon",0));
    am->save("ui",new UIAsset("csb/animation/barrier/cannon"));
    delete am;
}

- (void)test4Collider {
    BaseCollider* collider = new BaseCollider();
    delete collider;
    
    collider = new RectCollider();
    delete collider;
    
    collider = new CircleCollider();
    delete collider;

    collider = new EllipseCollider();
    delete collider;
}

- (void)test5Gepgraphy {
    GeographicNode* node = new GeographicNode();
    delete node;
    
    GeographicNodeManager* gnm = GeographicNodeManager::getInstance();
    gateway->clear();
    
    GeographicNodeSize* gns = new GeographicNodeSize();
    delete gns;

    GeographicNodeSlope* gnsl = new GeographicNodeSlope();
    delete gnsl;
    
    GeographicBuilder* builder = new GeographicBuilder();
    delete builder;
    
}

- (void)test6Property {
    BaseBehaviourProperty* peroperty = new BaseBehaviourProperty();
    delete peroperty;
    
    peroperty = new OrnamentBehaviourProperty("sample", 1, 1.0f,1.0f, 1.0f);
    delete peroperty;

    peroperty = new UIBehaviourProperty("sample", 1);
    delete peroperty;

    peroperty = new UnitBehaviourProperty("sample", 1);
    delete peroperty;

    peroperty = new WeaponBehaviourProperty("sample", 1);
    delete peroperty;
}

- (void)test7Route {
    BaseRouteSearch* search = new AstarRouteSearch();
    delete search;
    
    search = new DijkstraRouteSearch();
    delete search;

    search = new ManhattanDistanceRouteSearch();
    delete search;
    
    BaseAstarHeuristic* heuristic = new BaseAstarHeuristic();
    delete heuristic;

    heuristic = new AstarTwoPointDistanceHeuristic();
    delete heuristic;

    heuristic = new AstarTwoPointDistanceHeuristic();
    delete heuristic;
    
    DijkstraGeographicNodeLink* nodeLink = new DijkstraGeographicNodeLink(NULL,NULL);
    delete nodeLink;

}

- (void)test8Notify {
    Notifier* notifier = new Notifier();
    delete notifier;
    
    NotifyManager* nm = NotifyManager::getInstance();
    gateway->destroy();
}

- (void)test9CannonFiniteState {
    CannonBehaviourAttackState* cbas = new CannonBehaviourAttackState();
    delete cbas;

    CannonBehaviourSearchState* cbss = new CannonBehaviourSearchState();
    delete cbss;

    CannonBehaviourDestroyState* cbds = new CannonBehaviourDestroyState();
    delete cbds;

    CannonBehaviourTouchBeganState* cbtbs = new CannonBehaviourTouchBeganState();
    delete cbtbs;

    CannonBehaviourTouchEndState* cbtes = new CannonBehaviourTouchEndState();
    delete cbtes;
    
    FiniteStateMachine<CannonBehaviour>* stateMachine = new FiniteStateMachine<CannonBehaviour>(NULL);
    stateMachine->add("attack",new CannonBehaviourAttackState());
    stateMachine->add("search",new CannonBehaviourSearchState());
    stateMachine->add("destroy",new CannonBehaviourDestroyState());
    stateMachine->add("touchBegan",new CannonBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new CannonBehaviourTouchEndState());
    delete stateMachine;
}

- (void)test10DummyFiniteState {
    DummyBarrierDestroyState* dbds = new DummyBarrierDestroyState();
    delete dbds;
    
    FiniteStateMachine<DummyBarrierBehaviour>* stateMachine = new FiniteStateMachine<DummyBarrierBehaviour>(NULL);
    stateMachine->add("destroy",new DummyBarrierDestroyState());
    delete stateMachine;
}

- (void)test11ElixirFiniteState {
    ElixirTankBehaviourDestroyState* etbds = new ElixirTankBehaviourDestroyState();
    delete etbds;

    ElixirTankBehaviourDamageState* etbdas = new ElixirTankBehaviourDamageState();
    delete etbdas;

    ElixirTankBehaviourTouchBeganState* etbtbs = new ElixirTankBehaviourTouchBeganState();
    delete etbtbs;

    ElixirTankBehaviourTouchEndState* etbtes = new ElixirTankBehaviourTouchEndState();
    delete etbtes;
    
    FiniteStateMachine<ElixirTankBehaviour>* stateMachine = new FiniteStateMachine<ElixirTankBehaviour>(NULL);
    stateMachine->add("destroy",new ElixirTankBehaviourDestroyState());
    stateMachine->add("damage",new ElixirTankBehaviourDamageState());
    stateMachine->add("touchBegan",new ElixirTankBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new ElixirTankBehaviourTouchEndState());
    
    delete stateMachine;
}

- (void)test12GoldStageFiniteState {
    GoldStrageBehaviourDestroyState* state1 = new GoldStrageBehaviourDestroyState();
    delete state1;
    
    GoldStrageBehaviourDamageState* state2 = new GoldStrageBehaviourDamageState();
    delete state2;
    
    GoldStrageBehaviourTouchBeganState* state3 = new GoldStrageBehaviourTouchBeganState();
    delete state3;
    
    GoldStrageBehaviourTouchEndState* state4 = new GoldStrageBehaviourTouchEndState();
    delete state4;
    
    FiniteStateMachine<GoldStrageBehaviour>* stateMachine = new FiniteStateMachine<GoldStrageBehaviour>(NULL);
    stateMachine->add("destroy",new GoldStrageBehaviourDestroyState());
    stateMachine->add("damage",new GoldStrageBehaviourDamageState());
    stateMachine->add("touchBegan",new GoldStrageBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new GoldStrageBehaviourTouchEndState());
    
    delete stateMachine;
}

- (void)test13MortarFiniteState {
    MortarBehaviourAttackState* state1 = new MortarBehaviourAttackState();
    delete state1;
    
    MortarBehaviourDestroyState* state2 = new MortarBehaviourDestroyState();
    delete state2;
    
    MortarBehaviourPauseState* state3 = new MortarBehaviourPauseState();
    delete state3;
    
    MortarBehaviourTouchBeganState* state4 = new MortarBehaviourTouchBeganState();
    delete state4;

    MortarBehaviourTouchEndState* state5 = new MortarBehaviourTouchEndState();
    delete state5;
    
    FiniteStateMachine<MortarBehaviour>* stateMachine = new FiniteStateMachine<MortarBehaviour>(NULL);
    stateMachine->add("attack",new MortarBehaviourAttackState());
    stateMachine->add("destroy",new MortarBehaviourDestroyState());
    stateMachine->add("pause",new MortarBehaviourPauseState());
    stateMachine->add("touchBegan",new MortarBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new MortarBehaviourTouchEndState());
    
    delete stateMachine;
}

- (void)test14TurretFiniteState {
    TurretBehaviourDestroyState* state1 = new TurretBehaviourDestroyState();
    delete state1;
    
    TurretBehaviourTouchBeganState* state2 = new TurretBehaviourTouchBeganState();
    delete state2;
    
    TurretBehaviourTouchEndState* state3 = new TurretBehaviourTouchEndState();
    delete state3;
    
    FiniteStateMachine<TurretBehaviour>* stateMachine = new FiniteStateMachine<TurretBehaviour>(NULL);
    stateMachine->add("destroy",new TurretBehaviourDestroyState());
    stateMachine->add("touchBegan",new TurretBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new TurretBehaviourTouchEndState());
    
    delete stateMachine;
}

- (void)test15WoodFenceHFiniteState {
    WoodFenceHBehaviourDestroyState* state1 = new WoodFenceHBehaviourDestroyState();
    delete state1;
    
    WoodFenceHBehaviourTouchBeganState* state2 = new WoodFenceHBehaviourTouchBeganState();
    delete state2;
    
    WoodFenceHBehaviourTouchEndState* state3 = new WoodFenceHBehaviourTouchEndState();
    delete state3;
    
    FiniteStateMachine<WoodFenceHBehaviour>* stateMachine = new FiniteStateMachine<WoodFenceHBehaviour>(NULL);
    stateMachine->add("destroy",new WoodFenceHBehaviourDestroyState());
    stateMachine->add("touchBegan",new WoodFenceHBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new WoodFenceHBehaviourTouchEndState());
    
    delete stateMachine;
}

- (void)test16WoodFenceVFiniteState {
    WoodFenceVBehaviourDestroyState* state1 = new WoodFenceVBehaviourDestroyState();
    delete state1;
    
    WoodFenceVBehaviourTouchBeganState* state2 = new WoodFenceVBehaviourTouchBeganState();
    delete state2;
    
    WoodFenceVBehaviourTouchEndState* state3 = new WoodFenceVBehaviourTouchEndState();
    delete state3;
    
    FiniteStateMachine<WoodFenceVBehaviour>* stateMachine = new FiniteStateMachine<WoodFenceVBehaviour>(NULL);
    stateMachine->add("destroy",new WoodFenceVBehaviourDestroyState());
    stateMachine->add("touchBegan",new WoodFenceVBehaviourTouchBeganState());
    stateMachine->add("touchEnd",new WoodFenceVBehaviourTouchEndState());
    
    delete stateMachine;
}

- (void)test17DummyNodeFiniteState {
    DummyNode5BehaviourNormalState* state1 = new DummyNode5BehaviourNormalState();
    delete state1;
    
    DummyNode5BehaviourBlinkState* state2 = new DummyNode5BehaviourBlinkState();
    delete state2;
    
    FiniteStateMachine<DummyNode5Behaviour>* stateMachine = new FiniteStateMachine<DummyNode5Behaviour>(NULL);
    stateMachine->add("normal",new DummyNode5BehaviourNormalState());
    stateMachine->add("blink",new DummyNode5BehaviourBlinkState());
    
    delete stateMachine;
}

- (void)test18LoadingUIFiniteState {
    LoadingUIBehaviourLoadingState* state1 = new LoadingUIBehaviourLoadingState();
    delete state1;
    
    FiniteStateMachine<LoadingUIBehaviour>* stateMachine = new FiniteStateMachine<LoadingUIBehaviour>(NULL);
    stateMachine->add("loading",new LoadingUIBehaviourLoadingState());
    
    delete stateMachine;
}

- (void)test19LoadingUIFiniteState {
    LoadingUIBehaviourLoadingState* state1 = new LoadingUIBehaviourLoadingState();
    delete state1;
    
    FiniteStateMachine<LoadingUIBehaviour>* stateMachine = new FiniteStateMachine<LoadingUIBehaviour>(NULL);
    stateMachine->add("loading",new LoadingUIBehaviourLoadingState());
    
    delete stateMachine;
}

- (void)test20LogoUIFiniteState {
    LogoUIBehaviourFadeInState* state1 = new LogoUIBehaviourFadeInState();
    delete state1;
    
    FiniteStateMachine<LogoUIBehaviour>* stateMachine = new FiniteStateMachine<LogoUIBehaviour>(NULL);
    stateMachine->add("fadein",new LogoUIBehaviourFadeInState());
    
    delete stateMachine;
}

- (void)test21ArcherFiniteState {
    ArcherBehaviourMoveState* state1 = new ArcherBehaviourMoveState();
    delete state1;

    ArcherBehaviourAttackState* state2 = new ArcherBehaviourAttackState();
    delete state2;

    ArcherBehaviourWinState* state3 = new ArcherBehaviourWinState();
    delete state3;

    ArcherBehaviourLoseState* state4 = new ArcherBehaviourLoseState();
    delete state4;
    
    FiniteStateMachine<ArcherBehaviour>* stateMachine = new FiniteStateMachine<ArcherBehaviour>(NULL);
    stateMachine->add("move",new ArcherBehaviourMoveState());
    stateMachine->add("attack",new ArcherBehaviourAttackState());
    stateMachine->add("win",new ArcherBehaviourWinState());
    stateMachine->add("lose",new ArcherBehaviourLoseState());
    
    delete stateMachine;
}

- (void)test21BarbarianFiniteState {
    BarbarianBehaviourMoveState* state1 = new BarbarianBehaviourMoveState();
    delete state1;
    
    BarbarianBehaviourAttackState* state2 = new BarbarianBehaviourAttackState();
    delete state2;
    
    BarbarianBehaviourWinState* state3 = new BarbarianBehaviourWinState();
    delete state3;
    
    BarbarianBehaviourLoseState* state4 = new BarbarianBehaviourLoseState();
    delete state4;
    
    FiniteStateMachine<BarbarianBehaviour>* stateMachine = new FiniteStateMachine<BarbarianBehaviour>(NULL);
    stateMachine->add("move",new BarbarianBehaviourMoveState());
    stateMachine->add("attack",new BarbarianBehaviourAttackState());
    stateMachine->add("win",new BarbarianBehaviourWinState());
    stateMachine->add("lose",new BarbarianBehaviourLoseState());
    
    delete stateMachine;
}

- (void)test22DummyUnitFiniteState {
    DummyUnitBehaviourMoveState* state1 = new DummyUnitBehaviourMoveState();
    delete state1;
    
    DummyUnitBehaviourAttackState* state2 = new DummyUnitBehaviourAttackState();
    delete state2;
    
    FiniteStateMachine<DummyUnitBehaviour>* stateMachine = new FiniteStateMachine<DummyUnitBehaviour>(NULL);
    stateMachine->add("move",new DummyUnitBehaviourMoveState());
    stateMachine->add("attack",new DummyUnitBehaviourAttackState());
    
    delete stateMachine;
}

- (void)test23GiantFiniteState {
    GiantBehaviourMoveState* state1 = new GiantBehaviourMoveState();
    delete state1;
    
    GiantBehaviourAttackState* state2 = new GiantBehaviourAttackState();
    delete state2;

    GiantBehaviourWinState* state3 = new GiantBehaviourWinState();
    delete state3;

    GiantBehaviourLoseState* state4 = new GiantBehaviourLoseState();
    delete state4;
    
    FiniteStateMachine<GiantBehaviour>* stateMachine = new FiniteStateMachine<GiantBehaviour>(NULL);
    stateMachine->add("move",new GiantBehaviourMoveState());
    stateMachine->add("attack",new GiantBehaviourAttackState());
    stateMachine->add("win",new GiantBehaviourWinState());
    stateMachine->add("lose",new GiantBehaviourLoseState());
    
    delete stateMachine;
}

- (void)test24GoblinFiniteState {
    GoblinBehaviourMoveState* state1 = new GoblinBehaviourMoveState();
    delete state1;
    
    GoblinBehaviourAttackState* state2 = new GoblinBehaviourAttackState();
    delete state2;
    
    GoblinBehaviourWinState* state3 = new GoblinBehaviourWinState();
    delete state3;
    
    GoblinBehaviourLoseState* state4 = new GoblinBehaviourLoseState();
    delete state4;
    
    FiniteStateMachine<GoblinBehaviour>* stateMachine = new FiniteStateMachine<GoblinBehaviour>(NULL);
    stateMachine->add("move",new GoblinBehaviourMoveState());
    stateMachine->add("attack",new GoblinBehaviourAttackState());
    stateMachine->add("win",new GoblinBehaviourWinState());
    stateMachine->add("lose",new GoblinBehaviourLoseState());
    
    delete stateMachine;
}

- (void)test25TowerArcherFiniteState {
    TowerArcherBehaviourSearchState* state1 = new TowerArcherBehaviourSearchState();
    delete state1;
    
    TowerArcherBehaviourAttackState* state2 = new TowerArcherBehaviourAttackState();
    delete state2;
    
    TowerArcherBehaviourWinState* state3 = new TowerArcherBehaviourWinState();
    delete state3;
    
    TowerArcherBehaviourLoseState* state4 = new TowerArcherBehaviourLoseState();
    delete state4;
    
    FiniteStateMachine<TowerArcherBehaviour>* stateMachine = new FiniteStateMachine<TowerArcherBehaviour>(NULL);
    stateMachine->add("search",new TowerArcherBehaviourSearchState());
    stateMachine->add("attack",new TowerArcherBehaviourAttackState());
    stateMachine->add("win",new TowerArcherBehaviourWinState());
    stateMachine->add("lose",new TowerArcherBehaviourLoseState());
    
    delete stateMachine;
}

- (void)test26WallBreakerFiniteState {
    WallBreakerBehaviourMoveState* state1 = new WallBreakerBehaviourMoveState();
    delete state1;
    
    WallBreakerBehaviourAttackState* state2 = new WallBreakerBehaviourAttackState();
    delete state2;
    
    WallBreakerBehaviourWinState* state3 = new WallBreakerBehaviourWinState();
    delete state3;
    
    WallBreakerBehaviourLoseState* state4 = new WallBreakerBehaviourLoseState();
    delete state4;
    
    FiniteStateMachine<WallBreakerBehaviour>* stateMachine = new FiniteStateMachine<WallBreakerBehaviour>(NULL);
    stateMachine->add("move",new WallBreakerBehaviourMoveState());
    stateMachine->add("attack",new WallBreakerBehaviourAttackState());
    stateMachine->add("win",new WallBreakerBehaviourWinState());
    stateMachine->add("lose",new WallBreakerBehaviourLoseState());
    
    delete stateMachine;
}

- (void)test27ArrowFiniteState {
    ArrowBehaviourActiveBezier2DState* state1 = new ArrowBehaviourActiveBezier2DState();
    delete state1;
    
    ArrowBehaviourActiveBezier3DState* state2 = new ArrowBehaviourActiveBezier3DState();
    delete state2;
    
    ArrowBehaviourDestroyState* state3 = new ArrowBehaviourDestroyState();
    delete state3;
    
    FiniteStateMachine<ArrowBehaviour>* stateMachine = new FiniteStateMachine<ArrowBehaviour>(NULL);
    stateMachine->add("active2", new ArrowBehaviourActiveBezier2DState());
    stateMachine->add("active3", new ArrowBehaviourActiveBezier3DState());
    stateMachine->add("destroy", new ArrowBehaviourDestroyState());
    
    delete stateMachine;
}

- (void)test28CannonFiniteState {
    CannonBulletBehaviourActiveState* state1 = new CannonBulletBehaviourActiveState();
    delete state1;
    
    CannonBulletBehaviourDestroyState* state2 = new CannonBulletBehaviourDestroyState();
    delete state2;
    
    FiniteStateMachine<CannonBulletBehaviour>* stateMachine = new FiniteStateMachine<CannonBulletBehaviour>(NULL);
    stateMachine->add("active", new CannonBulletBehaviourActiveState());
    stateMachine->add("destroy", new CannonBulletBehaviourDestroyState());
    
    delete stateMachine;
}

- (void)test29CannonFiniteState {
    MortarBulletBehaviourActiveState* state1 = new MortarBulletBehaviourActiveState();
    delete state1;
    
    MortarBulletBehaviourDestroyState* state2 = new MortarBulletBehaviourDestroyState();
    delete state2;
    
    FiniteStateMachine<MortarBulletBehaviour>* stateMachine = new FiniteStateMachine<MortarBulletBehaviour>(NULL);
    stateMachine->add("active", new MortarBulletBehaviourActiveState());
    stateMachine->add("destroy", new MortarBulletBehaviourDestroyState());
    
    delete stateMachine;
}

- (void)test30Commmand {
    
    BaseCommand* command = new UICommand();
    delete command;

    command = new OrnamentCommand();
    delete command;

    command = new WeaponCommand();
    delete command;

    command = new UnitCommand();
    delete command;
    
    CommandManager* cm = CommandManager::getInstance();
    cm->destroy();
    
}

- (void)test31BehaviourManager {
    BehaviourManager* bm = BehaviourManager::getInstance();
    bm->destroy();
}

- (void)test32BehaviourQueue {
    BehaviourQueue* bq = BehaviourQueue::getInstance();
    bq->destroy();
}

- (void)test33BehaviourIdManager {
    BehaviourIdManager* bm = BehaviourIdManager::getInstance();
    bm->destroy();
}

- (void)test34Behaviour {
    BaseBehaviour* behaviour = new CannonBehaviour(NULL);
    delete behaviour;

    behaviour = new DummyBarrierBehaviour(NULL);
    delete behaviour;

    behaviour = new ElixirTankBehaviour(NULL);
    delete behaviour;
    
    behaviour = new GoldStrageBehaviour(NULL);
    delete behaviour;

    behaviour = new GraveBehaviour(NULL);
    delete behaviour;

    behaviour = new TurretBehaviour(NULL);
    delete behaviour;

    behaviour = new WoodFenceHBehaviour(NULL);
    delete behaviour;

    behaviour = new WoodFenceVBehaviour(NULL);
    delete behaviour;

    behaviour = new DummyNode1Behaviour(NULL);
    delete behaviour;

    behaviour = new DummyNode2Behaviour(NULL);
    delete behaviour;

    behaviour = new DummyNode3Behaviour(NULL);
    delete behaviour;

    behaviour = new DummyNode4Behaviour(NULL);
    delete behaviour;

    behaviour = new DummyNode5Behaviour(NULL);
    delete behaviour;

    behaviour = new GrassBehaviour(NULL);
    delete behaviour;
    
    behaviour = new GeographyEditorBehaviour();
    delete behaviour;

    behaviour = new LoadingUIBehaviour();
    delete behaviour;

    behaviour = new ArrowViewerBehaviour();
    delete behaviour;

    behaviour = new AsterRouteSearchTestBehaviour();
    delete behaviour;

    behaviour = new AstarRouteSearchViewerBehaviour();
    delete behaviour;

    behaviour = new DijkstraRouteSearchTestBehaviour();
    delete behaviour;

    behaviour = new DijkstraRouteSearchViewerBehaviour();
    delete behaviour;

    behaviour = new GeographyTestUIBehaviour();
    delete behaviour;
    
    behaviour = new ArcherBehaviour();
    delete behaviour;

    behaviour = new BarbarianBehaviour();
    delete behaviour;

    behaviour = new GiantBehaviour();
    delete behaviour;
    
    behaviour = new GoblinBehaviour();
    delete behaviour;

    behaviour = new WallBreakerBehaviour();
    delete behaviour;

    behaviour = new TowerArcherBehaviour();
    delete behaviour;
    
    behaviour = new ArrowBehaviour(NULL,NULL);
    delete behaviour;

    behaviour = new CannonBulletBehaviour(NULL,0);
    delete behaviour;

    behaviour = new MortarBulletBehaviour(NULL,NULL);
    delete behaviour;
    
}

- (void)test35Parameter {
    Parameter* parameter = new Parameter();
    parameter->add<int>("param1",1);
    parameter->add<float>("param2",1.0f);
    parameter->add<std::string>("param3","string");
    delete parameter;
}


@end
