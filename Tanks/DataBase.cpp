#include "DataBase.h"

<<<<<<< HEAD
void DataBase::loadFont() {
	//wczytywanie czcionek
	if (!FontHolder.load(arus::Font::DisposableDroid, "Data/Fonts/DisposableDroidBB_bld.otf"))
		throw "Wystapil blad podczas wczytywania czcionek.";
}

void DataBase::load() {
	stats.resetToDefaultStats();
	loadResources();
}

void DataBase::loadResources() {
	//wczytywanie tekstur
	if (TextureHolder.load(arus::Textures::brick, "Data/Textures/brick.jpg") &&
		TextureHolder.load(arus::Textures::logo, "Data/Textures/logo.png") &&
		TextureHolder.load(arus::Textures::ice, "Data/Textures/ice.jpg") &&
		TextureHolder.load(arus::Textures::bullet, "Data/Textures/bullet.png") &&
		TextureHolder.load(arus::Textures::sBullet, "Data/Textures/bulletS.png") &&
		TextureHolder.load(arus::Textures::cursor, "Data/Textures/cursor.png") &&
		TextureHolder.load(arus::Textures::eagle, "Data/Textures/eagle.jpg") &&
		TextureHolder.load(arus::Textures::grass, "Data/Textures/grass.png") &&
		TextureHolder.load(arus::Textures::player11, "Data/Textures/player-1-1.png") &&
		TextureHolder.load(arus::Textures::player21, "Data/Textures/player-2-1.png") &&
		TextureHolder.load(arus::Textures::player12, "Data/Textures/player-1-2.png") &&
		TextureHolder.load(arus::Textures::player22, "Data/Textures/player-2-2.png") &&
		TextureHolder.load(arus::Textures::enemyFast, "Data/Textures/enemy_fast.png") &&
		TextureHolder.load(arus::Textures::enemyHeavy, "Data/Textures/enemy_heavy.png") &&
		TextureHolder.load(arus::Textures::enemyNormal, "Data/Textures/enemy_normal.png") &&
		TextureHolder.load(arus::Textures::enemyRandom, "Data/Textures/enemy_random.png") &&
		TextureHolder.load(arus::Textures::tankDestroy, "Data/Textures/tank_destroy.png") &&
		TextureHolder.load(arus::Textures::spawn, "Data/Textures/spawn.png") &&
		TextureHolder.load(arus::Textures::steel, "Data/Textures/steel.jpg") &&
		TextureHolder.load(arus::Textures::tankMenu, "Data/Textures/tank_menu.png") &&
		TextureHolder.load(arus::Textures::flag, "Data/Textures/flaga.png") &&
		TextureHolder.load(arus::Textures::tankIcon, "Data/Textures/tank_icon.png") &&
		TextureHolder.load(arus::Textures::water, "Data/Textures/water.png") &&
		TextureHolder.load(arus::Textures::arrows, "Data/Textures/arrows.jpg") &&
		TextureHolder.load(arus::Textures::PTS, "Data/Textures/PTS.jpg") &&
		TextureHolder.load(arus::Textures::tanks, "Data/Textures/tanks_loadscreen.jpg") &&
		TextureHolder.load(arus::Textures::granadePU, "Data/Textures/granade.png") &&
		TextureHolder.load(arus::Textures::lifePU, "Data/Textures/life.png") &&
		TextureHolder.load(arus::Textures::pistolPU, "Data/Textures/pistol.png") &&
		TextureHolder.load(arus::Textures::shieldPU, "Data/Textures/shield.png") &&
		TextureHolder.load(arus::Textures::speedPU, "Data/Textures/speed.png") &&
		TextureHolder.load(arus::Textures::swimPU, "Data/Textures/swim.png") &&
		TextureHolder.load(arus::Textures::swim, "Data/Textures/additionalSwim.png") &&
		TextureHolder.load(arus::Textures::bulletDestroy, "Data/Textures/bullet_destroy.png") &&
		TextureHolder.load(arus::Textures::shield, "Data/Textures/additionalShield.png")
		) {
	}
	else {
		throw "Wystapil blad podczas wczytywania tekstur";
=======

DataBase::~DataBase() {
	//if (thread && thread->joinable()) {
	//	std::cout << "Join from destructor." << std::endl;
	//	thread->join();
		//delete thread;
	//}
	if (myThread) delete myThread;
}

void DataBase::load() {
	//in main thread
	loadMenuItems();
	//other thread
	//thread = new std::thread([this] {loadResources(); });
	myThread = new MyThread(std::thread([this] {loadResources(); }));
}

void DataBase::loadMenuItems() {
	std::lock_guard<std::mutex> locker(mu);

	TextureHolder.load(arus::Textures::logo, "Data/Textures/logo.png");
	TextureHolder.load(arus::Textures::tankMenu, "Data/Textures/tank_menu.png");
	FontHolder.load(arus::Font::DisposableDroid, "Data/Fonts/DisposableDroidBB_bld.otf");
}

void DataBase::loadResources(){
	std::lock_guard<std::mutex> locker(mu);
	//wczytywanie tekstur
	TextureHolder.load(arus::Textures::brick, "Data/Textures/brick.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::ice, "Data/Textures/ice.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::bullet, "Data/Textures/bullet.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::sBullet, "Data/Textures/bulletS.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::cursor, "Data/Textures/cursor.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::eagle, "Data/Textures/eagle.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::grass, "Data/Textures/grass.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::player11, "Data/Textures/player-1-1.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::player21, "Data/Textures/player-2-1.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::player12, "Data/Textures/player-1-2.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::player22, "Data/Textures/player-2-2.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::enemyFast, "Data/Textures/enemy_fast.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::enemyHeavy, "Data/Textures/enemy_heavy.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::enemyNormal, "Data/Textures/enemy_normal.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::enemyRandom, "Data/Textures/enemy_random.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::tankDestroy, "Data/Textures/tank_destroy.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::spawn, "Data/Textures/spawn.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::steel, "Data/Textures/steel.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::flag, "Data/Textures/flaga.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::tankIcon, "Data/Textures/tank_icon.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::water, "Data/Textures/water.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::arrows, "Data/Textures/arrows.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::PTS, "Data/Textures/PTS.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::tanks, "Data/Textures/tanks_loadscreen.jpg");
	Sleep(200);
	TextureHolder.load(arus::Textures::granadePU, "Data/Textures/granade.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::lifePU, "Data/Textures/life.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::pistolPU, "Data/Textures/pistol.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::shieldPU, "Data/Textures/shield.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::speedPU, "Data/Textures/speed.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::swimPU, "Data/Textures/swim.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::swim, "Data/Textures/additionalSwim.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::bulletDestroy, "Data/Textures/bullet_destroy.png");
	Sleep(200);
	TextureHolder.load(arus::Textures::shield, "Data/Textures/additionalShield.png");
	std::cout << "Loaded all." << std::endl;

	allLoaded = true;
}

bool DataBase::isFullyLoaded() {
	if (allLoaded == false) return false;

	if (myThread->joinable()) {
		//std::cout << "Loader Thread Joined." << std::endl;
		//thread->join();
		delete myThread;
>>>>>>> origin/master
	}

	return true;
}

void DataBase::interrupt(){
	if (myThread) myThread->interrupt();
}

sf::Texture& DataBase::get(arus::Textures t) {
	return TextureHolder.get(t);
}

sf::Font& DataBase::get(arus::Font f) {
	return FontHolder.get(f);
}

Stats& DataBase::getStats() {
	return stats;
}