#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

int main() {


	sf::RenderWindow window;
	window.create(sf::VideoMode(1280, 720), "Aquela tela de DVD");
	window.setFramerateLimit(60);

	sf::RectangleShape rect;
	sf::Vector2f rectPosition(100, 100);

	rect.setPosition(rectPosition);
	rect.setSize(sf::Vector2f(100, 100));
	
	
	float xvelocity = 3;
	float yvelocity = 3;
	

	while (window.isOpen()) {
		sf::Event event;


		while (window.pollEvent(event)) {


			if (event.type == sf::Event::Closed) {
				window.close();
				if (sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) window.close();
			
			}

			//"physics"


			if (rectPosition.x < 0 || rectPosition.x > 1280 - 100) xvelocity *= -1;
			if (rectPosition.y < 0 || rectPosition.y > 720 - 100) yvelocity *= -1;

			rectPosition.x += xvelocity;
			rectPosition.y += yvelocity;
			rect.setPosition(rectPosition);

			// renderer

			window.clear(sf::Color::Black);
			window.draw(rect);
			window.display();

		
		}
	
	}

	return 0;

}