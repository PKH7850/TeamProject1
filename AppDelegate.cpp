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
	if (!glview) {
<<<<<<< HEAD
		glview = GLViewImpl::createWithRect("test", Rect(0, 0, 720, 1280));
		//      glview->setFrameZoomFactor(0.5f);    //디버깅시 출력되는 창의 크기를 줄여준다.
=======
		glview = GLViewImpl::createWithRect("test", Rect(0, 0, 1280, 720));
		//glview 는 윈도우즈에서만 작동하므로, 포팅하여도 안드로이드에선 작동하지 않는다.
		glview->setFrameZoomFactor(0.5f);    //디버깅시 출력되는 창의 크기를 줄여준다.
>>>>>>> bf76176ed3ad869ffbb8588add04fbf6bad7146b
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
}