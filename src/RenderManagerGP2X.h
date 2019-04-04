/*=============================================================================
Blobby Volley 2
Copyright (C) 2006 Jonathan Sieber (jonathan_sieber@yahoo.de)
Copyright (C) 2006 Daniel Knobe (daniel-knobe@web.de)

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
=============================================================================*/

#pragma once

#include <SDL/SDL.h>
#include <vector>

#include "RenderManager.h"

/*! \class RenderManagerGP2X
	\brief SDL Render Manager for GP2X
	\details as SDLRenderManager, but uses scaled down textures
*/
class RenderManagerGP2X : public RenderManager
{
	public:
		RenderManagerGP2X();

		void init(int xResolution, int yResolution, bool fullscreen) override;
		void deinit() override;
		void draw() override;
		void refresh() override;

		bool setBackground(const std::string& filename) override;
		void setBlobColor(int player, Color color) override;

		void setBall(const Vector2& position, float rotation) override;
		void setBlob(int player, const Vector2& position,
				float animationState) override;

		virtual void setScore(int leftScore, int rightScore,
				   bool leftWarning, bool rightWarning);
		virtual void setTime(const std::string& t);

		void drawText(const std::string& text, Vector2 position, unsigned int flags = TF_NORMAL) override;
		virtual void drawImage(const std::string& filename, Vector2 position) {};

	private:
		SDL_Surface* mBackground;
		SDL_Surface* mBallShadow;

		std::vector<SDL_Surface*> mBall;
		std::vector<SDL_Surface*> mStandardBlob;
		std::vector<SDL_Surface*> mStandardBlobShadow;
		std::vector<SDL_Surface*> mLeftBlob;
		std::vector<SDL_Surface*> mLeftBlobShadow;
		std::vector<SDL_Surface*> mRightBlob;
		std::vector<SDL_Surface*> mRightBlobShadow;

		std::vector<SDL_Surface*> mFont;
		std::vector<SDL_Surface*> mHighlightFont;
		std::vector<SDL_Surface*> mSmallFont;
		std::vector<SDL_Surface*> mHighlightSmallFont;

		SDL_Surface *mScreen;

		Vector2 mBallPosition;
		float mBallRotation;
		Vector2 mLeftBlobPosition;
		float mLeftBlobAnimationState;
		Vector2 mRightBlobPosition;
		float mRightBlobAnimationState;

		int mLeftPlayerScore;
		int mRightPlayerScore;
		bool mLeftPlayerWarning;
		bool mRightPlayerWarning;

		std::string mLeftPlayerName;
		std::string mRightPlayerName;
		std::string mTime;

		SDL_Surface* colorSurface(SDL_Surface *surface, Color color);

};

