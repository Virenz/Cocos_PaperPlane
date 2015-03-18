#ifndef __GameScene_H__
#define __GameScene_H__

#include "cocos2d.h"
#include "extensions/cocos-ext.h"
#include "ui/CocosGUI.h"
#include "cocostudio/CocoStudio.h"
#include "editor-support/cocostudio/CCSGUIReader.h"


USING_NS_CC;
USING_NS_CC_EXT;
using namespace ui;
using namespace cocostudio;
#include "SimpleAudioEngine.h"
using namespace CocosDenshion;

class GameScene : public cocos2d::Layer
{
public:
    static Scene* createScene();
    virtual bool init();  
    void menuCloseCallback(Ref* pSender);
	CREATE_FUNC(GameScene);

	void resetMusic();
	void addUI();
	void addEdge();
	void addPlayer();
	void addEnemy(Sprite* bg);
	void addContactEvent();
	void addTouchEvent();

	bool onTouchBegan(Touch *touch, Event *unused_event);
	void onTouchMoved(Touch *touch, Event *unused_event);
	void onTouchEnded(Touch *touch, Event *unused_event);
	bool onContactBegin(PhysicsContact& contact);

	void update(float dt);

	void showGameOverLayer();

private:
	Size WIN_SIZE;
	Vec2 ORIGIN;

	// ready UI
	Layout* readyUI;
	Layer* layer;

	// �߽�
	Sprite* edge;
	Sprite* wallLeft;
	Sprite* wallRight;
	Sprite* bg1;
	Sprite* bg2;
	Size bgSize;
	
	Sprite* player;			// ���
	Vector<Sprite*> enemy;	// ����

	bool firstTouch;		// �Ƿ�ʼ��Ϸ
	bool isOver;			// ��Ϸ�Ƿ����

	int fps;
	int ang;				// �ɻ��Ƕ�
	Vec2 touchPos;			// ������
	bool isTouched;			// �Ƿ���

	// ��¼����
	double score;
	Label* lbScore;


};

#endif // __GameScene_H__
