#include "Menu.h"
//#include"DataBase.h"
extern DataBase DATABASE;

Menu::Menu(MyWindow& window)
	:target(window)
	, logo(arus::Textures::logo)
	, tank(arus::Textures::tankMenu, sf::Vector2f(30, 30), sf::Vector2f(48, 44))
	, text()
	, currenltyChoosed(0)
{
	std::string s[4] = { "One Player", "Two Players", "Construction", "Exit" };

	logo.setPosition((window.getSize().x / 2.f) - logo.getLocalBounds().width / 2.f, window.getSize().y * 0.1f);
	logo.setOrigin(0.0f, 0.f);

	for (int i = 0; i < 4; i++) {
		text[i].setFont(DATABASE.get(arus::Font::DisposableDroid));
		text[i].setString(s[i]);
		text[i].setCharacterSize(40);
		text[i].setPosition((window.getSize().x / 2.f) - 45.f, 50.f * i + 330.f);
	}

	tank.setScale(0.9f, 0.9f);
	tank.setPosition(text[0].getPosition().x - 70, text[0].getPosition().y + 10);
	tank.setOrigin(0.0f, 0.f);
}

void Menu::start() {//fixed update
	while (target.isOpen()) {
		events();
		update();
		render();
	}
}

void Menu::events() {
	sf::Event e;
	while (target.pollEvent(e)) {
		switch (e.type) {
		case sf::Event::KeyPressed:
			if (e.key.code == sf::Keyboard::Up) {
				currenltyChoosed--;
				if (currenltyChoosed < 0) currenltyChoosed = 3;
			}
			else if (e.key.code == sf::Keyboard::Down) {
				currenltyChoosed++;
				if (currenltyChoosed > 3) currenltyChoosed = 0;
			}
			else if (e.key.code == sf::Keyboard::Return) {
				choose();
			}
			break;
		}
		if (e.type == sf::Event::Closed) target.close();
	}
}

void Menu::update() {
	sf::Vector2f pos = text[currenltyChoosed].getPosition();
	tank.setPosition(pos.x - 70, pos.y + 10);
	tank.update();
}

void Menu::render() {
	target.clear(sf::Color::Black);

	logo >> target;
	tank >> target;

	for (auto t : text) target.draw(t);

	target.display();
}
<<<<<<< HEAD
void Menu::choose() {
=======
void Menu::choose(){

	if (!DATABASE.isFullyLoaded() && currenltyChoosed != 3) return;

>>>>>>> origin/master
	if (DATABASE.getStats().isCustomMap == true)
	{
		DATABASE.getStats().resetToDefaultStats();
		DATABASE.getStats().isCustomMap = true;
		DATABASE.getStats().currLevel = 0;
	}
	else {
		DATABASE.getStats().resetToDefaultStats();
	}

	if (currenltyChoosed == 0) { // 1
		Game game(target);
		game.run();
	}
	else if (currenltyChoosed == 1) { //2
		Game game(target, true);
		game.run();
	}
	else if (currenltyChoosed == 2) { // con
		Construction con(target);
		con.start();
	}
	else if (currenltyChoosed == 3) { //exit
		target.close();
		//try {
		//	DATABASE.interrupt();
		//}
		//catch (std::logic_error& err) {
		//	std::cout << err.what() << std::endl;
		//}
		
	}
}