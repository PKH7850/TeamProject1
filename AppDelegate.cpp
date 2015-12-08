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
		glview = GLViewImpl::createWithRect("test", Rect(0, 0, 1280, 720));
		//glview �� ����������� �۵��ϹǷ�, �����Ͽ��� �ȵ���̵忡�� �۵����� �ʴ´�.
		glview->setFrameZoomFactor(0.5f);    //������ ��µǴ� â�� ũ�⸦ �ٿ��ش�.
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