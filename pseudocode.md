START SnakeGame

DEFINE constants:
    WIDTH = 20
    HEIGHT = 20

INITIALIZE variables:
    snake = [] // List to store the positions of the snake's body
    direction = "STOP" // Initial direction of the snake
    score = 0 // Initial score
    fruitPosition = (random position within WIDTH and HEIGHT) // Random position for fruit
    gameOver = FALSE

FUNCTION Setup():
    SET snake to initial position [(WIDTH / 2), (HEIGHT / 2)]
    SET direction to "STOP"
    SET score to 0
    SET fruitPosition to (random position within WIDTH and HEIGHT)
    SET gameOver to FALSE

FUNCTION Draw():
    CLEAR console
    DRAW top wall using "#" for WIDTH + 2 characters
    
    FOR each row from 0 to HEIGHT:
        DRAW left wall "#"
        
        FOR each column from 0 to WIDTH:
            IF current position is snake head THEN
                DRAW snake head "*"
            ELSE IF current position is fruit THEN
                DRAW fruit "%"
            ELSE IF current position is part of snake body THEN
                DRAW snake body "*"
            ELSE
                DRAW empty space " "
        
        DRAW right wall "#"
    
    DRAW bottom wall using "#" for WIDTH + 2 characters
    DISPLAY score

FUNCTION Input():
    IF a key is pressed THEN
        READ key
        SWITCH key:
            CASE 'a': SET direction to "LEFT"
            CASE 'd': SET direction to "RIGHT"
            CASE 'w': SET direction to "UP"
            CASE 's': SET direction to "DOWN"
            CASE 'x': SET gameOver to TRUE

FUNCTION Logic():
    STORE previous head position in prevX and prevY
    
    UPDATE head position based on current direction:
        IF direction is "LEFT" THEN x--
        IF direction is "RIGHT" THEN x++
        IF direction is "UP" THEN y--
        IF direction is "DOWN" THEN y++
    
    WRAP around logic:
        IF x >= WIDTH THEN x = 0
        IF x < 0 THEN x = WIDTH - 1
        IF y >= HEIGHT THEN y = 0
        IF y < 0 THEN y = HEIGHT - 1
    
    CHECK for collision with itself:
        FOR each segment in snake body:
            IF current segment position matches head position THEN
                SET gameOver to TRUE
    
    CHECK if snake eats fruit:
        IF head position matches fruitPosition THEN
            INCREMENT score by 10
            GENERATE new random fruitPosition
            ADD new segment to snake body

FUNCTION Main():
    CALL Setup()
    
    WHILE NOT gameOver DO:
        CALL Draw()
        CALL Input()
        CALL Logic()
        
        SLEEP for a short duration (to control speed)

END SnakeGame
