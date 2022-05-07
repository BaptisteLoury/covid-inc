#ifndef LANDTILE_H
#define LANDTILE_H

#include <vector>
#include "AbstractTile.hpp"
#include "Severity.hpp"
#include "utils/Timer.hpp"

class LandTile : virtual public AbstractTile {
protected:
        /**
         * @brief Niveau de sévérité du virus associé à la case.
         * None s'il n'y a pas de virus
         */
        VirusSeverity _virus;
        /**
         * @brief Temps à partir du quel la case a été infectée
         */
        std::chrono::_V2::steady_clock::duration _infectionTiming;

        /**
         * @brief Ajoute une case t à un tableau n si elle est du bon type
         * 
         * @param t tile
         * @param n neighbours list
         */
        void addNeighbIfLandTile(AbstractTile * t, std::vector<LandTile *>& n);
public:
        /**
         * @brief Construct a new Land Tile object
         * 
         */
        LandTile();

        /**
         * @brief Construct a new Land Tile object
         * 
         * @param x 
         * @param y 
         */
        LandTile(int x, int y);

        /**
         * @brief Construct a new Land Tile object
         * 
         * @param t TileType
         * @param c Associated char
         * @param x 
         * @param y 
         */
        LandTile(TileType t, const char * c,int x, int y);

        /**
         * @brief True si la case a une VirusSeverity différente de None
         * 
         * @return true 
         * @return false 
         */
        bool isInfected();

        /**
         * @brief Get the Virus Severity object
         * 
         * @return VirusSeverity 
         */
        VirusSeverity getVirusSeverity();

        /**
         * @brief Get the Neighbours
         * 
         * @param carte 
         * @return std::vector<LandTile *> 
         */
        virtual std::vector<LandTile *> getNeighbours(std::vector<std::vector<AbstractTile *>> &carte);

        /**
         * @brief Get the Infected Neighbours
         * 
         * @param carte 
         * @return std::vector<LandTile *> 
         */
        virtual std::vector<LandTile *> getInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte);

        /**
         * @brief Get the Not Infected Neighbours
         * 
         * @param carte 
         * @return std::vector<LandTile *> 
         */
        virtual std::vector<LandTile *> getNotInfectedNeighbours(std::vector<std::vector<AbstractTile *>> &carte);

        /**
         * @brief Dessine la case dans la fenêtre à la position x;y
         * 
         * @param w fenêtre
         * @param x 
         * @param y 
         */
        virtual void draw(WINDOW * w, int x, int y);

        /**
         * @brief Initialise le timer et change le VirusSeverity à LOW
         * 
         */
        void infect();

        /**
         * @brief stop le timer
         * 
         */
        void cure();

        /**
         * @brief Get the Infected Time object
         * 
         * @return Timer 
         */
        std::chrono::_V2::steady_clock::duration getInfectionTiming();
};

#endif