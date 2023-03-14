#include "../Ball/Ball.hpp"
#include "../Vector2D/Vector2D.hpp"

#include <raylib-cpp.hpp>
#include <vector>
#include <algorithm>
#include <string>

struct CompareByX
{
    inline bool operator() (const Ball &a, const Ball &b)
    {
        return (a.pos.x < b.pos.x);
    }
};
class Scene2 {
public:
    std::vector<Ball> balls;

    Scene2();
    ~Scene2();
    Scene2(Scene2&&) noexcept;
    Scene2& operator=(Scene2 &&other);
    void Swap(Scene2& right);

    void Draw();
    void Update();
    void AddBallToScene2();
    void MoveBallByMouse();

private:
    Ball *pSelectedBall = nullptr;
};
