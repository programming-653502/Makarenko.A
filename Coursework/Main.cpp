#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
using namespace sf;
using namespace std;

float offsetX = 0, offsetY = 0;
//const int H = 12;
//const int W = 40;
const int H = 24;
const int W = 80;

static void Scream()
{
	Time t2 = milliseconds(3000);
	Clock clock;
	int i = 0;
	Texture sc[3];
	Sprite SC[3];
	Music Sc[3];
	Sc[i].openFromFile("SC0.ogg");

	sc[i].loadFromFile("SC0.png");
	SC[i].setTexture(sc[i]);
	i++;
	sc[i].loadFromFile("SC1.png");
	SC[i].setTexture(sc[i]);
	i++;
	RenderWindow Scream(VideoMode(1600, 1200), "Scream");
	
		Scream.draw(SC[i - 1]);
		Sc[i].play();
		//Sleep(3000)
		Scream.close();
}

String TileMap[H] = {
	
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                                                              B",
	"B                                                 B                            B",
	"B                                BBBBBBBBBBBBBBBBBBCBBBBBBBBBBBBBBBBBBBBBB     B",
	"B          BB                  BBBB  00BB                                B     B",
	"B      B   BB                 BBBB   00BB         0000                BBBB     B",
	"B     BB V CC                    000000 V                                      B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBVVB0B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB    B",
	"B                                B     BB                                B     B",
	"B                                B     BB                                B     B",
	"B                                B     BB                                B     B",
	"B          BB                    B     BB                                B     B",
	"B      B   BB                 BBBB     BB         0000                BBBB     B",
	"B     BB V BB                    B     BB                                B     B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
	"B                                B     BB                                B     B",
	"B                                B     BB                                B     B",
	"B                                B     BB                                B     B",
	"B          BB                    B     BB                                B     B",
	"B      B   BB                 BBBB     BB         0000                BBBB     B",
	"B     BB V BB                    B     BB                                B     B",
	"BBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBBB",
};
class PLAYER
{
	public:
		float dx, dy;
		FloatRect rect;
		bool onGround;
		Sprite sprite;
		float currentFrame;

		
		PLAYER(Texture &image)
		{
			sprite.setTexture(image);
			
			sprite.setTextureRect(IntRect(0, 64, 32, 32));
			rect= FloatRect(64,64, 32, 32);
			dx = dy = 0;
			currentFrame = 0;
		}
		void update(float time)
		{
			rect.left += dx*time;
			Collision(0);
			if (!onGround) dy = dy + 0.0005*time;
			rect.top += dy*time;
			onGround = false;
			Collision(1);
			
			currentFrame += 0.005*time;
			if (currentFrame > 12) currentFrame -= 12;

			if(dx>0) sprite.setTextureRect(IntRect(32 * int(currentFrame), 64, 32, 32));
			if(dx<0) sprite.setTextureRect(IntRect(32 * int(currentFrame) + 32, 64, -32, 32));
			
			sprite.setPosition(rect.left-offsetX,rect.top-offsetY);
			dx = 0;
		}
		void Collision(int dir)
		{
			for (int i = rect.top / 32; i<(rect.top + rect.height) / 32; i++)
				for (int j = rect.left / 32 ;j<(rect.left + rect.width) / 32; j++)
				{
					if (TileMap[i][j] == 'B')
					{
						if ((dx>0) && (dir == 0)) rect.left = j * 32 - rect.width;
						if ((dx<0) && (dir == 0)) rect.left = j * 32 + 32;
						if ((dy>0) && (dir == 1)) { rect.top = i * 32 - rect.height;  dy = 0;   onGround = true; }
						if ((dy<0) && (dir == 1)) { rect.top = i * 32 + 32;   dy = 0; }
					}

					if (TileMap[i][j] == '0')
					{
						TileMap[i][j] = ' ';
					}

					if (TileMap[i][j] == 'Ñ')
					{
						Scream();
						TileMap[i][j] = ' ';
					}

					if (TileMap[i][j] == 'V')
					{
						Scream();
						TileMap[i][j] = ' ';
					}

				}

		}
		
};

int main()
{
	RenderWindow window(VideoMode(1344, 768), "Game");
	//1344, 768
	Texture horrors[20];
	Texture t;
	t.loadFromFile("demon.png");
	Texture t2;
	t2.loadFromFile("texture.png");
	/*Sprite s2;
	s2.setTexture(t2);
	s2.setTextureRect(IntRect(704,320,32,32));*/
 	float currentFrame = 0;

	PLAYER p(t);
	Sprite rectangle; //(Vector2f(32, 32))
	rectangle.setTexture(t2);
	Music music;
	music.openFromFile("Perekhrest_-_Paranoia.ogg");
	music.play();
	Clock clock;
	
	
	

	while (window.isOpen())
	{
		float time = clock.getElapsedTime().asMilliseconds();
		clock.restart();
		Event event;
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
				window.close();
		}
		if (Keyboard::isKeyPressed(Keyboard::Left))
		{
			p.dx = -0.2;
		}
		if (Keyboard::isKeyPressed(Keyboard::Right))
		{
			p.dx = 0.2;
		}
		if (Keyboard::isKeyPressed(Keyboard::Up))
		{
			if (p.onGround) { p.dy = -0.3; p.onGround = false;}
		}
		p.update(time);
		if(p.rect.left>672)offsetX = p.rect.left-672;
		offsetY = p.rect.top-384;
		window.clear(Color::Black);
		for(int i=0; i<H; i++)
			for (int j = 0; j < W; j++)
			{
				if (TileMap[i][j] == 'B') { rectangle.setTextureRect(IntRect(512, 64, 32, 32)); }				
				if (TileMap[i][j] == '0') { rectangle.setTextureRect(IntRect(160, 256, 32, 32)); }
				if (TileMap[i][j] == ' ') { rectangle.setTextureRect(IntRect(640, 256, 32, 32)); }
				if (TileMap[i][j] == 'Ñ') { rectangle.setTextureRect(IntRect(512, 64, 32, 32)); }
				if (TileMap[i][j] == 'V') { rectangle.setTextureRect(IntRect(640, 256, 32, 32)); }
				rectangle.setPosition(j*32-offsetX,i*32-offsetY);
				window.draw(rectangle);
			}
		window.draw(p.sprite);
		window.display();
	}
	return 0;
}





