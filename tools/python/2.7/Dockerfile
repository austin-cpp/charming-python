FROM charming/compiler:latest

RUN set -o xtrace \
  && : === DOWNLOAD SOURCE === \
    && mkdir -p /usr/src/cpython \
    && cd /usr/src/cpython \
    && hg clone https://hg.python.org/cpython .

RUN set -o xtrace \
  && : === INSTALL BUILD DEPENDENCIES === \
    && build_packages=" \
        libreadline6-dev \
      " \
    && apt-get update \
    && apt-get install -y --no-install-recommends $build_packages \
  && : === BUILD ==== \
    && python_version="2.7" \
    && cd /usr/src/cpython \
    && hg update $python_version \
    && mkdir -p /opt/python-${python_version} \
    && ./configure prefix=/opt/python-${python_version} \
    && make \
    && make install \
  && : === CLEANUP === \
    && rm -rf /tmp/* \
              /var/lib/apt/lists/* \
    && apt-get purge -y --auto-remove $build_packages