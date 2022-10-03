#ifndef TOY_ROBOT_DEFINITIONS
#define TOY_ROBOT_DEFINITIONS

template<typename E, E first, E head>
void right(E& v)
{
    if(head==v) v = first;
}

template<typename E, E first, E head, E next, E... tail>
void right(E& v)
{
    if(head == v) 
        v = next;
    else
        right<E, first, next, tail...>(v);
}

template<typename E, E first, E last>
void left(E&v)
{
    if(first==v) v = last;
}

template<typename E, E first, E head, E next, E... tail>
void left(E& v)
{
    if(next == v)
        v = head;
    else
        left<E, first, next, tail...>(v);
}


template<typename E, E first, E... values>
struct CircularEnum
{
    static void adv_right(E& v)
    {
        right<E, first, first, values...>(v);
    }

    static void adv_left(E& v)
    {
        left<E, first, first, values...>(v);
    }
};

typedef enum ERobotDirection
{
    ERobotDirection_North = 0,
    ERobotDirection_East = 1,
    ERobotDirection_South = 2,
    ERobotDirection_West = 3,
    ERobotDirection_Invalid = 4
} ERobotDirection_t;

typedef CircularEnum<ERobotDirection,
ERobotDirection::ERobotDirection_North,
ERobotDirection::ERobotDirection_East,
ERobotDirection::ERobotDirection_South,
ERobotDirection::ERobotDirection_West
> ERobotDirection_values;

typedef enum ERobotRotate
{
    ERobotRotate_CCW,
    ERobotRotate_CW,
    ERobotRotate_Invalid
} ERobotRotate_t;

typedef enum ECommand
{
    ECommand_Place,
    ECommand_Left,
    ECommand_Right,
    ECommand_Move,
    ECommand_Report,
    ECommand_Close,
    ECommand_Invalid
} ECommand_t;

typedef struct SPosition
{
    int x;
    int y;
} SPosition_t;

#endif //TOY_ROBOT_DEFINITIONS