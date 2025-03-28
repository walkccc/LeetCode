// Common configuration
const VERSION = '0.16.21';
const BASE_URL = `https://cdn.jsdelivr.net/npm/katex@${VERSION}/dist`;
const COMMON_ATTRS = {
  crossOrigin: 'anonymous',
};

// KaTeX definitions
const KATEX = {
  stylesheet: {
    type: 'link',
    attrs: {
      rel: 'stylesheet',
      href: `${BASE_URL}/katex.min.css`,
      integrity:
        'sha384-zh0CIslj+VczCZtlzBcjt5ppRcsAmDnRem7ESsYwWwg3m/OaJ2l4x7YBZl9Kxxib',
      ...COMMON_ATTRS,
    },
  },
  main: {
    type: 'script',
    attrs: {
      defer: true,
      src: `${BASE_URL}/katex.min.js`,
      integrity:
        'sha384-Rma6DA2IPUwhNxmrB/7S3Tno0YY7sFu9WSYMCuulLhIqYSGZ2gKCJWIqhBWqMQfh',
      ...COMMON_ATTRS,
    },
  },
  autoRender: {
    type: 'script',
    attrs: {
      defer: true,
      src: `${BASE_URL}/contrib/auto-render.min.js`,
      integrity:
        'sha384-hCXGrW6PitJEwbkoStFjeJxv+fSOOQKOPbJxSfM6G5sWZjAyWhXiTIIAmQqnlLlh',
      ...COMMON_ATTRS,
    },
  },
};

// Create and append elements
const link = document.createElement(KATEX.stylesheet.type);
Object.assign(link, KATEX.stylesheet.attrs);
document.head.appendChild(link);

const script1 = document.createElement(KATEX.main.type);
Object.assign(script1, KATEX.main.attrs);

const script2 = document.createElement(KATEX.autoRender.type);
Object.assign(script2, KATEX.autoRender.attrs);

// Wait for both scripts to load before rendering
Promise.all([
  new Promise((resolve) => {
    script1.onload = resolve;
    document.body.appendChild(script1);
  }),
  new Promise((resolve) => {
    script2.onload = resolve;
    document.body.appendChild(script2);
  }),
]).then(() => {
  renderMathInElement(document.body, {
    delimiters: [
      { left: '$$', right: '$$', display: true },
      { left: '$', right: '$', display: false },
    ],
  });
});
