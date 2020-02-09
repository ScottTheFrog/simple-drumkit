#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>


bool kickbool = false;
bool snarebool = false;
bool hithatcbool = false;
bool hithatobool = false;
bool tomb1bool = false;
bool tomb2bool = false;
bool tomb3bool = false;
bool crashbool = false;

int main()
{
    sf::RenderWindow window(sf::VideoMode(540,260), "Drumset simulator");
    window.setFramerateLimit(60);

    sf::SoundBuffer kick_buffer;
    sf::SoundBuffer snare_buffer;
    sf::SoundBuffer hithatc_buffer;
    sf::SoundBuffer hithato_buffer;
    sf::SoundBuffer crash_buffer;
    sf::SoundBuffer tomb1_buffer;
    kick_buffer.loadFromFile("kick.wav");
    snare_buffer.loadFromFile("snare.wav");
    hithatc_buffer.loadFromFile("hithatc.wav");
    hithato_buffer.loadFromFile("hithato.wav");
    crash_buffer.loadFromFile("crash.wav");
    tomb1_buffer.loadFromFile("tomb1.wav");
    sf::Sound sound1, sound2, sound3, sound4, sound5, sound6;
    sound1.setBuffer(kick_buffer);
    sound2.setBuffer(snare_buffer);
    sound3.setBuffer(hithatc_buffer);
    sound4.setBuffer(hithato_buffer);
    sound5.setBuffer(crash_buffer);
    sound6.setBuffer(tomb1_buffer);

    sf::Texture texture;
    sf::Texture bg;
    texture.loadFromFile("textures.png");
    bg.loadFromFile("background.jpg");

    sf::Sprite  bg_s;
    bg_s.setTexture(bg);
    bg_s.setPosition(sf::Vector2f(0.0f,0.0f));
    bg_s.scale(sf::Vector2f(0.4f, 0.4f));

    sf::Sprite  snare_s;
    snare_s.setTexture(texture);
    snare_s.setTextureRect(sf::IntRect(30, 0, 13, 13));
    snare_s.setPosition(sf::Vector2f(192.0f,116.0f));
    snare_s.scale(sf::Vector2f(5.0f, 5.0f));

    sf::Sprite  kick_s;
    kick_s.setTexture(texture);
    kick_s.setTextureRect(sf::IntRect(14, 0, 16, 16));
    kick_s.setPosition(sf::Vector2f(256.0f,116.0f));
    kick_s.scale(sf::Vector2f(6.0f, 6.0f));

    sf::Sprite  tomb_s;
    tomb_s.setTexture(texture);
    tomb_s.setTextureRect(sf::IntRect(43, 0, 9, 9));
    tomb_s.setPosition(sf::Vector2f(212.0f,66.0f));
    tomb_s.scale(sf::Vector2f(5.0f, 5.0f));

    sf::Sprite  tomb_s2;
    tomb_s2.setTexture(texture);
    tomb_s2.setTextureRect(sf::IntRect(43, 0, 9, 9));
    tomb_s2.setPosition(sf::Vector2f(260.0f,56.0f));
    tomb_s2.scale(sf::Vector2f(6.0f, 6.0f));

    sf::Sprite  tomb_s3;
    tomb_s3.setTexture(texture);
    tomb_s3.setTextureRect(sf::IntRect(43, 0, 9, 9));
    tomb_s3.setPosition(sf::Vector2f(320.0f,50.0f));
    tomb_s3.scale(sf::Vector2f(7.0f, 7.0f));

    sf::Sprite  hithat_s;
    hithat_s.setTexture(texture);
    hithat_s.setTextureRect(sf::IntRect(0, 17, 23, 9));
    hithat_s.setPosition(sf::Vector2f(100.0f,100.0f));
    hithat_s.scale(sf::Vector2f(4.0f, 4.0f));

    sf::Sprite  crash_s;
    crash_s.setTexture(texture);
    crash_s.setTextureRect(sf::IntRect(0, 17, 23, 9));
    crash_s.setPosition(sf::Vector2f(100.0f,40.0f));
    crash_s.scale(sf::Vector2f(6.0f, 6.0f));
    crash_s.rotate(-15.0f);

    while (window.isOpen()){
        sf::Event event;
        while (window.pollEvent(event)){
            if (event.type == sf::Event::Closed)
                window.close();}

        if (sf::Keyboard::isKeyPressed(sf::Keyboard::V)){
            if (kickbool == true){
                kickbool = false;

                sound1.play();}}
        else{
            kickbool = true;

        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::F)){
            if (snarebool){
                snarebool = false;
                sound2.play();}}
        else{
            snarebool = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::D)){
            if (hithatcbool){
                hithatcbool = false;
                sound3.play();
                sound4.stop();}}
        else{
            hithatcbool = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::X)){
            if (hithatobool){
                hithatobool = false;
                sound4.play();}}
        else{
            hithatobool = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::S)){
            if (crashbool){
                crashbool = false;
                sound5.play();}}
        else{
            crashbool = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::G)){
            if (tomb1bool){
                tomb1bool = false;
                sound6.setPitch(1.0f);
                sound6.play();}}
        else{
            tomb1bool = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::B)){
            if (tomb2bool){
                tomb2bool = false;
                sound6.setPitch(0.5f);
                sound6.play();}}
        else{
            tomb2bool = true;
        }
        if (sf::Keyboard::isKeyPressed(sf::Keyboard::H)){
            if (tomb3bool){
                tomb3bool = false;
                sound6.setPitch(0.2f);
                sound6.play();}}
        else{
            tomb3bool = true;
        }


        window.clear(sf::Color::White);
        window.draw(bg_s);
        window.draw(snare_s);
        window.draw(kick_s);
        window.draw(tomb_s);
        window.draw(tomb_s2);
        window.draw(tomb_s3);
        window.draw(hithat_s);
        window.draw(crash_s);
        window.display();
    }

    return 0;
}

