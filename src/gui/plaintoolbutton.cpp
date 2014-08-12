/*
  Copyright (c) 2012, BuildmLearn Contributors listed at http://buildmlearn.org/people/
  All rights reserved.

  Redistribution and use in source and binary forms, with or without
  modification, are permitted provided that the following conditions are met:

  * Redistributions of source code must retain the above copyright notice, this
    list of conditions and the following disclaimer.

  * Redistributions in binary form must reproduce the above copyright notice,
    this list of conditions and the following disclaimer in the documentation
    and/or other materials provided with the distribution.

  * Neither the name of the BuildmLearn nor the names of its
    contributors may be used to endorse or promote products derived from
    this software without specific prior written permission.

  THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
  AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
  IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE ARE
  DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE LIABLE
  FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
  DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
  SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
  CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
  OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
  OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
*/

#include "gui/plaintoolbutton.h"

#include <QToolButton>
#include <QStyle>
#include <QPainter>
#include <QPaintEvent>
#include <QStyleOption>


PlainToolButton::PlainToolButton(QWidget *parent) : QToolButton(parent), m_padding(0) {
}

PlainToolButton::~PlainToolButton() {
}

void PlainToolButton::paintEvent(QPaintEvent *e) {
  Q_UNUSED(e)

  QPainter p(this);
  QRect rect(QPoint(0, 0), size());

  // Set padding.
  rect.adjust(m_padding, m_padding, -m_padding, -m_padding);

  // Paint the icon.
  if (!isEnabled()) {
    p.setOpacity(0.4);
  }
  else if (underMouse()) {
    p.setOpacity(0.7);
  }

  icon().paint(&p, rect);
}

int PlainToolButton::padding() const {
  return m_padding;
}

void PlainToolButton::setPadding(int padding) {
  m_padding = padding;

  repaint();
}
