
import pygame
import sys
import random
from copy import deepcopy
 
# Game settings
WIDTH = 800
HEIGHT = 600
FPS = 60
CELL_SIZE = 10
PADDLE_WIDTH = 20
PADDLE_HEIGHT = 100
PADDLE_SPEED = 10
BALL_SPEED = 5
 
# Colors
WHITE = (255, 255, 255)
BLACK = (0, 0, 0)
RED = (255, 0, 0)
 
def game_of_life(board):
    new_board = deepcopy(board)
    for i in range(len(board)):
        for j in range(len(board[i])):
            alive_neighbors = sum([board[i + x][j + y] for x in range(-1, 2) for y in range(-1, 2)
                                   if 0 <= i + x < len(board) and 0 <= j + y < len(board[i]) and (x, y) != (0, 0)])
            if board[i][j] and (alive_neighbors < 2 or alive_neighbors > 3):
                new_board[i][j] = 0
            elif not board[i][j] and alive_neighbors == 3:
                new_board[i][j] = 1
    return new_board
 
def spawn_random_cells(board, cols, num_cells):
    for col in cols:
        indices = random.sample(range(len(board)), num_cells)
        for idx in indices:
            board[idx][col] = 1
 
def randomize_ball_velocity(velocity, min_speed, max_speed):
    return random.uniform(min_speed, max_speed) * (-1 if velocity < 0 else 1)
 
# Initialize Pygame
pygame.init()
screen = pygame.display.set_mode((WIDTH, HEIGHT))
pygame.display.set_caption("Pong with Conway's Game of Life")
clock = pygame.time.Clock()
 
# Paddle
paddle_y = HEIGHT // 2 - PADDLE_HEIGHT // 2
 
# Ball
ball = {'x': WIDTH - PADDLE_WIDTH - CELL_SIZE, 'y': paddle_y + PADDLE_HEIGHT // 2, 'dx': -BALL_SPEED, 'dy': 0, 'fired': False}
 
# Game of Life board
board = [[random.choice([0, 1]) if j < (WIDTH // 2 // CELL_SIZE) - 1 else 0 for j in range(WIDTH // CELL_SIZE)] for i in range(HEIGHT // CELL_SIZE)]
 
# Score and high score
score = 0
high_score = 0
 
# Game loop
running = True
while running:
    clock.tick(FPS)
 
    # Event handling
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            running = False
        if event.type == pygame.KEYDOWN and event.key == pygame.K_SPACE and not ball['fired']:
            ball['fired'] = True
            ball['y'] = paddle_y + PADDLE_HEIGHT // 2
 
    # Paddle movement
    keys = pygame.key.get_pressed()
    if keys[pygame.K_UP] and paddle_y > 0:
        paddle_y -= PADDLE_SPEED
    if keys[pygame.K_DOWN] and paddle_y < HEIGHT - PADDLE_HEIGHT:
        paddle_y += PADDLE_SPEED
 
    # Update Game of Life board
    board = game_of_life(board)
    spawn_random_cells(board, [0, 1], 5)
 
    # Ball movement
    if ball['fired']:
        ball['x'] += ball['dx']
        ball['y'] += ball['dy']
 
        # Reflect the ball when hitting the top or bottom
        if ball['y'] <= 0 or ball['y'] >= HEIGHT - CELL_SIZE:
            ball['dy'] *= -1
 
        # Reflect the ball when hitting the left side
        if ball['x'] <= 0:
            ball['dx'] *= -1
 
        # Game of Life cells collision
        cell_x, cell_y = int(ball['x'] // CELL_SIZE), int(ball['y'] // CELL_SIZE)
        if 0 <= cell_x < len(board[0]) and 0 <= cell_y < len(board) and board[cell_y][cell_x]:
            board[cell_y][cell_x] = 0
            ball['dx'] *= -1
 
        # Paddle collision
        if (WIDTH - PADDLE_WIDTH - CELL_SIZE <= ball['x'] <= WIDTH - PADDLE_WIDTH and
            paddle_y <= ball['y'] <= paddle_y + PADDLE_HEIGHT):
            ball['dx'] *= -1
            ball['dy'] = randomize_ball_velocity(ball['dy'], 0.5 * BALL_SPEED, 1.5 * BALL_SPEED)
            score += 1
            if score > high_score:
                high_score = score
 
        # Ball goes off the right side of the field
        if ball['x'] >= WIDTH - CELL_SIZE:
            ball = {'x': WIDTH - PADDLE_WIDTH - CELL_SIZE, 'y': paddle_y + PADDLE_HEIGHT // 2, 'dx': -BALL_SPEED, 'dy': 0, 'fired': False}
            score = 0
 
    # Draw the background
    screen.fill(BLACK)
 
    # Draw the Game of Life cells
    for i in range(len(board)):
        for j in range(len(board[i])):
            if board[i][j]:
                pygame.draw.rect(screen, WHITE, (j * CELL_SIZE, i * CELL_SIZE, CELL_SIZE, CELL_SIZE))
 
    # Draw the paddle
    pygame.draw.rect(screen, WHITE, (WIDTH - PADDLE_WIDTH, paddle_y, PADDLE_WIDTH, PADDLE_HEIGHT))
 
    # Draw the ball
    if ball['fired']:
        pygame.draw.rect(screen, RED, (ball['x'], ball['y'], CELL_SIZE, CELL_SIZE))
 
    # Draw the score and high score
    font = pygame.font.Font(None, 36)
    text = font.render(f"Score: {score}", True, WHITE)
    screen.blit(text, (WIDTH - 150, 10))
    text = font.render(f"High Score: {high_score}", True, WHITE)
    screen.blit(text, (WIDTH - 250, 50))
 
    # Update the display
    pygame.display.flip()
 
# Quit Pygame
pygame.quit()
sys.exit()
 