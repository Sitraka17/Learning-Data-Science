from manim import *

class ConvexFunction3D(ThreeDScene):
    def construct(self):
        # Définir la fonction convexe
        def convex_function(x, y):
            return x**2 + y**2

        # Créer les axes 3D
        axes = ThreeDAxes(
            x_range=[-3, 3, 1],
            y_range=[-3, 3, 1],
            z_range=[-1, 9, 1],
            axis_config={"color": BLUE},
        )

        # Créer la surface de la fonction convexe
        surface = Surface(
            lambda u, v: axes.c2p(u, v, convex_function(u, v)),
            u_range=[-3, 3],
            v_range=[-3, 3],
            resolution=(30, 30),
            fill_color=BLUE_E,
            fill_opacity=0.75,
            checkerboard_colors=[BLUE_D, BLUE_E],
        )

        # Ajouter les axes et la surface à la scène
        self.set_camera_orientation(phi=75 * DEGREES, theta=-45 * DEGREES)
        self.add(axes)
        self.add(surface)

        # Animer la rotation de la caméra
        self.begin_ambient_camera_rotation(rate=0.5)
        self.wait(10)
        self.stop_ambient_camera_rotation()

        # Garder la scène pendant quelques secondes
        self.wait(2)

# Pour exécuter la scène, utilisez la commande suivante dans votre terminal :
# manim -pql your_script_name.py ConvexFunction3D
