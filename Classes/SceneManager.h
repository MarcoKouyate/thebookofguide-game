#pragma once

class SceneManager {
public:
	void lose();

	static SceneManager* getInstance();

	

private:
    /* Here will be the instance stored. */
    static SceneManager* instance;

    /* Private constructor to prevent instancing. */
    SceneManager();
};