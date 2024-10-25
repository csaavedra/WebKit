/*
 * Copyright (C) 2010-2011 Nokia Corporation and/or its subsidiary(-ies)
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions
 * are met:
 * 1. Redistributions of source code must retain the above copyright
 *    notice, this list of conditions and the following disclaimer.
 * 2. Redistributions in binary form must reproduce the above copyright
 *    notice, this list of conditions and the following disclaimer in the
 *    documentation and/or other materials provided with the distribution.
 *
 * THIS SOFTWARE IS PROVIDED BY APPLE INC. AND ITS CONTRIBUTORS ``AS IS''
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO,
 * THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR
 * PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL APPLE INC. OR ITS CONTRIBUTORS
 * BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF
 * THE POSSIBILITY OF SUCH DAMAGE.
 */

#pragma once

#if USE(COORDINATED_GRAPHICS)

#include "IntPoint.h"
#include "IntPointHash.h"
#include "IntRect.h"
#include <wtf/TZoneMalloc.h>

namespace WebCore {

class CoordinatedBackingStoreProxy;

class CoordinatedBackingStoreProxyTile {
    WTF_MAKE_TZONE_ALLOCATED(CoordinatedBackingStoreProxyTile);
public:
    CoordinatedBackingStoreProxyTile(CoordinatedBackingStoreProxy&, const IntPoint&, const IntRect&);
    ~CoordinatedBackingStoreProxyTile();

    uint32_t tileID() const { return m_ID; }
    void ensureTileID();

    const IntPoint& position() const { return m_position; }
    const IntRect& rect() const { return m_rect; }
    const IntRect& dirtyRect() const { return m_dirtyRect; }
    bool isDirty() const;
    bool isReadyToPaint() const;

    void invalidate(const IntRect&);
    void markClean();
    void resize(const IntSize&);

private:
    CoordinatedBackingStoreProxy& m_tiledBackingStore;
    uint32_t m_ID;
    IntPoint m_position;
    IntRect m_rect;
    IntRect m_dirtyRect;
};

} // namespace WebCore

#endif // USE(COORDINATED_GRAPHICS)

