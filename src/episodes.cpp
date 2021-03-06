#include "remote.h"
#include "episodes.h"
#include "cube.h"

#include <cstdio>
#include <unistd.h>
#include <utility>
#include <cstdlib>
#include <iostream>

struct ColorF
{
    float r, g, b;
};

static inline float lerp(float a, float b, float t)
{
    return (1 - t) * a + t * b;
}

static inline ColorF blend_color(const ColorF &c1, const ColorF &c2, float t)
{
    return {
        lerp(c1.r, c2.r, t),
        lerp(c1.g, c2.g, t),
        lerp(c1.b, c2.b, t),
    };
}

static inline Color color_float_to_uint(const ColorF &color)
{
    return {(uint8_t)(color.r * 255), (uint8_t)(color.g * 255), (uint8_t)(color.b * 255)};
}

void do_s01e01(Cube *cube, RemoteSystem *remote)
{
    for(;;)
    {
        cube::lightTal(cube, {0, 0, 0}, {255, 0, 255});
        cube::commit(cube);
        usleep(250000);
        cube::lightTal(cube, {0, 0, 0}, {0, 0, 0});
        cube::commit(cube);
        usleep(250000);
    }
} // anonymous namespace

void do_s01e02(Cube *cube, RemoteSystem *remote)
{
    Color red = {255, 0, 0};
    Color green = {0, 255, 0};
    Color blue = {0, 0, 255};
    Color cyan = {0, 255, 255};
    Color magenta = {255, 0, 255};
    Color yellow = {255, 255, 0};
    Color white = {255, 255, 255};

    // Rouge x 4 r = b = g 
    cube::lightTal(cube, {0, 0, 0}, red);
    cube::lightTal(cube, {1, 1, 1}, red);
    cube::lightTal(cube, {2, 2, 2}, red);
    cube::lightTal(cube, {3, 3, 3}, red);

    // Blanc x 18
    cube::lightTal(cube, {3, 0, 0}, white);
    cube::lightTal(cube, {3, 1, 0}, white);
    cube::lightTal(cube, {3, 2, 0}, white);
    cube::lightTal(cube, {3, 3, 0}, white);
    cube::lightTal(cube, {2, 3, 0}, white);
    cube::lightTal(cube, {1, 3, 0}, white);
    cube::lightTal(cube, {0, 3, 0}, white);
    cube::lightTal(cube, {3, 0, 1}, white);
    cube::lightTal(cube, {3, 0, 2}, white);
    cube::lightTal(cube, {3, 0, 3}, white);
    cube::lightTal(cube, {2, 0, 3}, white);
    cube::lightTal(cube, {1, 0, 3}, white);
    cube::lightTal(cube, {0, 3, 1}, white);
    cube::lightTal(cube, {0, 3, 2}, white);
    cube::lightTal(cube, {0, 3, 3}, white);
    cube::lightTal(cube, {0, 3, 3}, white);
    cube::lightTal(cube, {0, 2, 3}, white);
    cube::lightTal(cube, {0, 1, 3}, white);
    cube::lightTal(cube, {0, 0, 3}, white);

    // Bleu x 9
    cube::lightTal(cube, {1, 0, 0}, blue);
    cube::lightTal(cube, {0, 1, 0}, blue);
    cube::lightTal(cube, {0, 0, 1}, blue);
    cube::lightTal(cube, {2, 1, 1}, blue);
    cube::lightTal(cube, {1, 2, 1}, blue);
    cube::lightTal(cube, {1, 1, 2}, blue);
    cube::lightTal(cube, {3, 2, 2}, blue);
    cube::lightTal(cube, {2, 3, 2}, blue);
    cube::lightTal(cube, {2, 2, 3}, blue);

    // Vert x 9
    cube::lightTal(cube, {1, 1, 0}, green);
    cube::lightTal(cube, {1, 0, 1}, green);
    cube::lightTal(cube, {0, 1, 1}, green);

    cube::lightTal(cube, {2, 2, 1}, green);
    cube::lightTal(cube, {2, 1, 2}, green);
    cube::lightTal(cube, {1, 2, 2}, green);

    cube::lightTal(cube, {3, 3, 2}, green); /////
    cube::lightTal(cube, {2, 3, 3}, green);
    cube::lightTal(cube, {3, 2, 3}, green);

    // Cyan x 6
    cube::lightTal(cube, {2, 2, 0}, cyan);
    cube::lightTal(cube, {2, 0, 2}, cyan);
    cube::lightTal(cube, {0, 2, 2}, cyan);

    cube::lightTal(cube, {3, 3, 1}, cyan);
    cube::lightTal(cube, {3, 1, 3}, cyan);
    cube::lightTal(cube, {1, 3, 3}, cyan);
    

    // Magenta x 6
    cube::lightTal(cube, {2, 0, 0}, magenta);
    cube::lightTal(cube, {0, 2, 0}, magenta);
    cube::lightTal(cube, {0, 0, 2}, magenta);

    cube::lightTal(cube, {3, 1, 1}, magenta);
    cube::lightTal(cube, {1, 3, 1}, magenta);
    cube::lightTal(cube, {1, 1, 3}, magenta);

    // Jaune x 12
    cube::lightTal(cube, {0, 1, 2}, yellow);
    cube::lightTal(cube, {1, 0, 2}, yellow);
    cube::lightTal(cube, {2, 0, 1}, yellow);
    cube::lightTal(cube, {0, 2, 1}, yellow);
    cube::lightTal(cube, {1, 2, 0}, yellow);
    cube::lightTal(cube, {2, 1, 0}, yellow);


    cube::lightTal(cube, {1, 2, 3}, yellow);
    cube::lightTal(cube, {2, 1, 3}, yellow);
    cube::lightTal(cube, {3, 1, 2}, yellow);
    cube::lightTal(cube, {1, 3, 2}, yellow);
    cube::lightTal(cube, {2, 3, 1}, yellow);
    cube::lightTal(cube, {3, 2, 1}, yellow);


    cube::commit(cube);
}

void do_s01e03(Cube *cube, RemoteSystem *remote)
{
    while (true)
    {
        uint32_t x, y, z;

        std::cout << "X";
        std::cin >> x;

        std::cout << "Y";
        std::cin >> y;

        std::cout << "Z";
        std::cin >> z;

        std::cout << "X : " << x << " y : " << y << " z : " << z << std::endl;

        cube::lightTal(cube, {x, y, z}, {255, 255, 255});
        cube::commit(cube);
    }
}

void do_s01e04(Cube *cube, RemoteSystem *remote)
{
    ColorF start = {1, 0, 0};
    ColorF end = {1, 1, 0};

    float t = 0;

    for (;;)
    {
        ColorF c = blend_color(start, end, t);

        for (uint8_t x = 1; x < 3; ++x)
        {
            for (uint8_t y = 1; y < 3; ++y)
            {
                for (uint8_t z = 1; z < 3; ++z)
                {
                    cube::lightTal(cube, {x, y, z}, color_float_to_uint(c));
                }
            }
        }

        t += 0.01f;

        if (t > 1.0f)
        {
            std::swap(start, end);
            t = 0.0f;
        }

        usleep(50000);

        cube::commit(cube);
    }
}

void do_multi_remotes(Cube* cube, RemoteSystem* remote)
{
    auto fill_cube = [&](Color fill_color){
        for (uint8_t x = 0; x < 4; ++x)
        {
            for (uint8_t y = 0; y < 4; ++y)
            {
                for (uint8_t z = 0; z < 4; ++z)
                {
                    cube::lightTal(cube, {x, y, z}, fill_color);
                }
            }
        }

        cube::commit(cube);
    };

    uint16_t buttons_1;
    uint16_t buttons_2;
    for(;;)
    {
        bool remote_1_has_event = false;
        bool remote_2_has_event = false;

        if ((buttons_1 = remote::get_remote_state(remote, 0)))
        {
            remote_1_has_event = true;
        }

        if ((buttons_2 = remote::get_remote_state(remote, 1)))
        {
            remote_2_has_event = true;
        }

        if (remote_1_has_event)
        {
            fill_cube({255, 0, 0});
            printf("Remote 1 received: %d\n", buttons_1);
        }
        if (remote_2_has_event)
        {
            fill_cube({0, 255, 0});
            printf("Remote 2 received: %d\n", buttons_2);
        }
    }
}

void do_s02e01(Cube *cube, RemoteSystem *remote)
{
    uint16_t button;
    Vec3 position = {0, 0, 0};
    cube::lightTal(cube, position, {255, 0, 255});
    cube::commit(cube);

    while (true)
    {
        button = remote::get_remote_state(remote, 0);
        if (button != 0)
        {
            if (button & 0x1)
            {
                position.x = (position.x + 1) % 4;
            }
            if (button & 0x2)
            {
                position.y = (position.y + 1) % 4;
            }
            if (button & 0x4)
            {
                position.z = (position.z + 1) % 4;
            }

            cube::lightTal(cube, position, {255, 0, 255});
            cube::commit(cube);
        }

        usleep(2500);
    }
}

void do_s02e02(Cube *cube, RemoteSystem *remote)
{
    uint16_t buttons[2];
    Vec3 positions[2];
    positions[0] = {0, 0, 0};
    positions[1] = {0, 0, 3};

    cube::lightTal(cube, positions[0], {255, 0, 0});
    cube::lightTal(cube, positions[1], {0, 255, 0});
    cube::commit(cube);

    auto move_dot = [&](Vec3& pos, uint16_t button, Color c){
        if (button != 0)
        {
            if (button & 0x1)
            {
                pos.x = (pos.x + 1) % 4;
            }
            if (button & 0x2)
            {
                pos.y = (pos.y + 1) % 4;
            }
            if (button & 0x4)
            {
                pos.z = (pos.z + 1) % 4;
            }
        }
    };

    while (true)
    {
        buttons[0] = remote::get_remote_state(remote, 0);
        buttons[1] = remote::get_remote_state(remote, 1);

        move_dot(positions[0], buttons[0], {255, 0, 0});
        move_dot(positions[1], buttons[1], {0, 255, 0});

        cube::lightTal(cube, positions[0], {255, 0, 0});
        cube::lightTal(cube, positions[1], {0, 255, 0});
        cube::commit(cube);

        usleep(2500);
    }
}

void do_fun_01(Cube *cube, RemoteSystem *remote)
{
    Vec3 pos = {0, 0, 0};
    ColorF c = {1, 1, 1};

    uint8_t axis = rand() % 3;
    uint8_t dir = 1;
    for(;;)
    {
        if (pos.x == 0 || pos.x == 3
            || pos.y == 0 || pos.y == 3
            || pos.z == 0 || pos.z == 3)
        {
            axis = rand() % 3;
            dir = rand() % 2 == 0 ? 1 : -1;
        }

        if (axis == 0) pos.x += dir;
        else if (axis == 1) pos.y += dir;
        else if (axis == 2) pos.z += dir;

        cube::lightTal(cube, pos, color_float_to_uint(c));
        cube::commit(cube);
        
        usleep(40000); /// 1/25 FPS.
    }
}

void do_s02e03(Cube *cube, RemoteSystem *remote)
{
    for (;;)
    {
        uint16_t buttons = 0;

        buttons = remote::get_remote_state(remote, 0);

        if (buttons)
        {
            printf("%d\n", buttons);

            uint8_t data = 0;

            if (buttons & 0x1) data |= 0x1;
            if (buttons & 0x2) data |= 0x2;
            if (buttons & 0x4) data |= 0x4;

            remote::toggle_led(remote, 0, data);
        }

        usleep(5000);
    }
}

namespace episodes
{
    void (*list_of_episodes[])(Cube *, RemoteSystem *remote) =
        {
            do_multi_remotes,
            do_s01e01,
            do_s01e02,
            do_s01e03,
            do_s01e04,
            do_s02e01,
            do_s02e02,
            do_s02e03,
            do_fun_01,
        };

    void start_episode(Cube *cube, RemoteSystem *remote, Episode episode)
    {
        printf("Starting episode %d\n", episode);
        list_of_episodes[episode](cube, remote);
    }
} // namespace episodes
