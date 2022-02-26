/* Author @daoluke */
#ifndef ZOFIA_FPS_COUNTER_CPP__
#define ZOFIA_FPS_COUNTER_CPP__

#include <SFML/System/Clock.hpp>
#include "../Typography.cpp"
#include "BaseView.cpp"
#include "BaseViewContext.cpp"

namespace zofia {

    class FpsCounterContext : public BaseViewContext {

    };

    class FpsCounter : public BaseView<FpsCounterContext> {
        private:
          sf::Clock m_delayTimer;
          sf::Clock m_fpsTimer;
          float m_fps = 0;
          int m_frameCount = 0;

          Typography *getText();

          std::function<void(std::map<std::string, std::unique_ptr<DrawableEntity>>)> m_func;

        public:
          FpsCounter();

          void update(FpsCounterContext &context) override;

          void draw(sf::RenderTarget &renderTarget) override;
    };

    Typography *FpsCounter::getText() {
        return dynamic_cast<Typography *>(m_entities["text"].get());
    }

    void FpsCounter::update(FpsCounterContext &context) {
        float x = 1.0f / 120;
        m_frameCount++;

        if (m_delayTimer.getElapsedTime().asSeconds() > x) {
            m_fps = m_frameCount / m_fpsTimer.restart().asSeconds();
            m_frameCount = 0;
            m_delayTimer.restart();
        }


        std::string text = "FPS " + std::to_string((int) m_fps);
        getText()->setText(text);
    }

    FpsCounter::FpsCounter() : BaseView<FpsCounterContext>("fps_counter") {
        this->addEntity("text", zofia::make_unique<Typography>());

        TypographyContext typographyContext;
        typographyContext.m_position = Position(10, 10);
        typographyContext.m_color = sf::Color::Red;
        typographyContext.m_thickness = 2;
        typographyContext.m_textSize = 30;

        getText()->update(typographyContext);
    }

    void FpsCounter::draw(sf::RenderTarget &renderTarget) {
        getText()->draw(renderTarget);
    }
}

#endif
