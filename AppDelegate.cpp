#include "AppDelegate.h"
#include "HelloWorldScene.h"
#include "MenuScene.h"

USING_NS_CC;

AppDelegate::AppDelegate() {

}

AppDelegate::~AppDelegate()
{
}

bool AppDelegate::applicationDidFinishLaunching() {
	auto director = Director::getInstance();
	auto glview = director->getOpenGLView();
	auto frameSize = glview->getFrameSize();
	if (!glview) {
		glview = GLView::createWithRect("TeamProject", Rect(0, 0, 360, 720));
	//	glview->setFrameZoomFactor(0.5f);    //디버깅시 출력되는 창의 크기를 줄여준다.
		director->setOpenGLView(glview);
	}

	glview->setDesignResolutionSize(1280, 720, ResolutionPolicy::EXACT_FIT);
	director->setDisplayStats(false);
	director->setAnimationInterval(1.0 / 60);
	auto scene = MenuScene::createScene();
	director->runWithScene(scene);

	return true;
}

void AppDelegate::applicationDidEnterBackground() {
	Director::getInstance()->stopAnimation();
}

void AppDelegate::applicationWillEnterForeground() {
	Director::getInstance()->startAnimation();
	Scene* runningScene = Director::getInstance()->getRunningScene();
}
