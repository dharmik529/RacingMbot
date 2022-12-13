import random
import pygame

PANEL_width = 1080
PANEL_highly = 720
FONT_PX = 15
makeblock = pygame.image.load('logo.png')   
pygame.init()
# Create a visual window
winSur = pygame.display.set_mode((PANEL_width, PANEL_highly))

font = pygame.font.SysFont("SimHei", 22)

bg_suface = pygame.Surface((PANEL_width, PANEL_highly), flags=pygame.SRCALPHA)

pygame.Surface.convert(bg_suface)

bg_suface.fill(pygame.Color(0, 0, 0, 28))

winSur.fill((0, 0, 0))

letter = ['m', 'a', 'k', 'e', 'b', 'l', 'o', 'c', 'k','P', 'y', 't', 'h', 'o', 'n']
texts = [
    font.render(str(letter[i]), True, (0, 255, 0)) for i in range(15)
]

# It is possible to place several columns of coordinates on the artboard and generate a list based on the screen bandwidth
column = int(PANEL_width / FONT_PX)
drops = [0 for i in range(column)]
while True:
    # Get the event from the queue
    for event in pygame.event.get():
        if event.type == pygame.QUIT:
            exit()
        elif event.type == pygame.KEYDOWN:

            chang = pygame.key.get_pressed()
            if (chang[32]):
                exit()

    # Pauses for a given number of milliseconds
    pygame.time.delay(30)
    winSur.blit(makeblock,(272 , 285))
    # The second parameter of reediting the image is sitting Angle coordinates
    winSur.blit(bg_suface, (0, 0))

    for i in range(len(drops)):
        text = texts[i%15]
            

        # Reedit the image for each coordinate point
        winSur.blit(text, (i * FONT_PX, drops[i] * FONT_PX))

        drops[i] += 1
        if drops[i] * 10 > PANEL_highly or random.random() > 0.95:
            drops[i] = 0

    pygame.display.flip()
