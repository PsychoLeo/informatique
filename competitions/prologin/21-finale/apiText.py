# This file was generated by stechec2-generator. DO NOT EDIT.

from enum import IntEnum
from typing import NamedTuple, List, Tuple  # noqa: F401

from _api import *


# Nombre de tours à jouer avant la fin de la partie.
NB_TOURS = 200

# Nombre de pandas par joueur.
NB_PANDAS = 2

# Nombre de tours nécessaires pour faire tomber un bébé panda.
NB_TOURS_PERTE_BEBE = 3

# Valeur max d'un pont (les valeurs sont comprises entre 1 et cette constante
# inclus).
VALEUR_MAX_PONT = 6

# Nombre de points obtenus à la capture d'un bébé pandas.
NB_POINTS_CAPTURE_BEBE = 10


# Types de cases
class case_type(IntEnum):
    LIBRE = 0  # <- Case libre
    OBSTACLE = 1  # <- Obstacle
    PONT = 2  # <- Pont
    BEBE = 3  # <- Bébé panda


# Directions cardinales
class direction(IntEnum):
    NORD_EST = 0  # <- Direction : nord-est
    SUD_EST = 1  # <- Direction : sud-est
    SUD = 2  # <- Direction : sud
    SUD_OUEST = 3  # <- Direction : sud-ouest
    NORD_OUEST = 4  # <- Direction : nord-ouest
    NORD = 5  # <- Direction : nord


# Erreurs possibles
class erreur(IntEnum):
    OK = 0  # <- L'action s'est effectuée avec succès.
    POSITION_INVALIDE = 1  # <- La position spécifiée n'est pas sur la rivière.
    POSITION_OBSTACLE = 2  # <- La position spécifiée est un obstacle.
    MAUVAIS_NOMBRE = 3  # <- La hauteur de la position spécifiée ne correspond pas.
    DEPLACEMENT_HORS_LIMITES = 4  # <- Ce déplacement fait sortir un panda des limites de la rivière.
    DIRECTION_INVALIDE = 5  # <- La direction spécifiée n'existe pas.
    MOUVEMENT_INVALIDE = 6  # <- Le panda ne peut pas se déplacer dans cette direction.
    POSE_INVALIDE = 7  # <- Le pont ne peut pas être placé a cette position et dans cette direction.
    ID_PANDA_INVALIDE = 8  # <- Le panda spécifié n'existe pas.
    ACTION_DEJA_EFFECTUEE = 9  # <- Une action a déjà été effectuée ce tour.
    DRAPEAU_INVALIDE = 10  # <- Le drapeau spécifié n'existe pas.
    DEPLACEMENT_EN_ARRIERE = 11  # <- La panda c'est déjà déplacé sur cette case.


# Types d'actions
class action_type(IntEnum):
    ACTION_DEPLACER = 0  # <- Action ``deplacer``.
    ACTION_POSER = 1  # <- Action ``poser``.


# Types de drapeau de débug
class debug_drapeau(IntEnum):
    AUCUN_DRAPEAU = 0  # <- Aucun drapeau, enlève le drapeau présent
    DRAPEAU_BLEU = 1  # <- Drapeau bleu
    DRAPEAU_VERT = 2  # <- Drapeau vert
    DRAPEAU_ROUGE = 3  # <- Drapeau rouge


# Case type pont, contient la case de début et de fin. La case de début a une
# valeur se décrémentant, celle de fin s'incrémente.
class pont_type(NamedTuple):
    debut_pos: Tuple[int, int]  # Position de la case de début
    fin_pos: Tuple[int, int]  # Position de la case de fin
    debut_val: int  # Valeur de la case de début
    fin_val: int  # Valeur de la case de début


# Panda et son joueur
class panda_info(NamedTuple):
    panda_pos: Tuple[int, int]  # Position du panda
    id_joueur: int  # Identifiant du joueur qui contrôle le panda
    id_panda: int  # Identifiant du panda relatif au joueur
    num_bebes: int  # Nombre de bébés qui sont portés par le panda parent


# Bébé panda à ramener.
class bebe_info(NamedTuple):
    bebe_pos: Tuple[int, int]  # Position du bébé panda
    id_bebe_joueur: int  # Identifiant du joueur qui peut saver le bébé


# Information sur un tour particulier.
class tour_info(NamedTuple):
    id_panda_joue: int  # Identifiant du panda qui joue
    id_tour: int  # Identifiant unique du tour (compteur)


# Information sur la carte de la partie en cours.
class carte_info(NamedTuple):
    taille_x: int  # La taille de la carte pour les coordonnées x [0; taille_x[
    taille_y: int  # La taille de la carte pour les coordonnées y [0; taille_y[


# Action représentée dans l'historique.
class action_hist(NamedTuple):
    type_action: action_type  # Type de l'action
    action_id_panda: int  # Identifiant du panda concerné par l'action
    dir: direction  # Direction visée par le panda durant le déplacement
    valeur_debut: int  # Valeur au début du pont posé (de 1 à 6 inclus)
    valeur_fin: int  # Valeur à la fin du pont posé (de 1 à 6 inclus)
    pos_debut: Tuple[int, int]  # Position du début du pont posé
    pos_fin: Tuple[int, int]  # Position de la fin du pont posé