FROM charming/python:latest

RUN set -o xtrace \
  && : ===  DOWNLOAD SOURCE === \
    && mkdir -p /usr/src/swig \
    && cd /usr/src/swig \
    && git clone https://github.com/swig/swig.git .

RUN set -o xtrace \
  && : === INSTALL BUILD DEPENDENCIES === \
    && build_packages=" \
        byacc \
        yodl \
      " \
    && apt-get update \
    && apt-get install -y --no-install-recommends $build_packages \
  && : === BUILD === \
    && swig_version="3.0.5" \
    && cd /usr/src/swig \
    && git checkout rel-${swig_version} \
    && ./autogen.sh \
    && ./configure --without-maximum-compile-warnings \
                   --without-alllang \
                   --with-python=/opt/python-2.7/bin/python \
    && make \
    && make install \
  && : === CLEANUP === \
    && rm -rf /tmp/* \
              /var/lib/apt/lists/* \
    && apt-get purge -y --auto-remove $build_packages